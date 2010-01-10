#include "matrix.h"
#include "math.h"
#include "wrong_size.h"

Matrix::Matrix() : num_columns(0), num_rows(0) {
    initialize();
}

Matrix::Matrix(unsigned int x, unsigned int y) : 
    num_columns(x), num_rows(y) {
        initialize();
}

Matrix::Matrix(const Matrix & copy) : num_columns(copy.columns()), num_rows(copy.rows()) {
    initialize();

    for (unsigned int i = 0; i < num_columns; ++i) {
        for (unsigned int i = 0; i < columns(); ++i) {
            for (unsigned int j = 0; j < rows(); ++j) {
                (*matrix)[i][j] = copy[i][j];
            }
        }
    }
}

Matrix::~Matrix() {
    delete matrix;
}

void Matrix::initialize() {
        matrix = new Vector<WrapperVector >(num_columns);

        for (unsigned int i = 0; i < num_columns; ++i) {
            (*matrix)[i].set_size(num_rows);
        }
}

/**
 * Reads values in matlab format from stdin. Assuming the input is
 * valid.
 *
 * @param in Standard input stream
 * @param matrix The matrix to give the values
 * @return The standard input stream
 */
std::istream & operator>>(std::istream & in, Matrix & matrix) {
    std::string input;
    in >> input;

    return in;
}

unsigned int Matrix::columns() const {
    return num_columns;
}
unsigned int Matrix::rows() const {
    return num_rows;
}

std::ostream & operator<<(std::ostream & out, const Matrix & matrix) {
    int maxDigit = 0;
    int n;
    for (unsigned int i = 0; i < matrix.columns(); ++i) {
        for (unsigned int j = 0; j < matrix.rows(); j++) {
            n = log10(matrix[i][j]);
            if (matrix[i][j] < 0)
                n++;
            if (n > maxDigit)  {
                maxDigit = n;
            }
        }
    }
    maxDigit++;

    std::string append = "";

    out << "[ ";

    for (unsigned int i = 0; i < matrix.columns(); ++i) {
        if (i != 0)
            out << "; ";
        for (unsigned int j = 0; j < matrix.rows(); j++) {
            append = "";
            int digit = 0;
            int n = matrix[i][j];
            if (n < 0) {
                digit++;
                n *= -1;
            }

            while (n >= 10) {
                digit++;
                n /= 10;
            }
            append.append(maxDigit - digit  +1, ' ');
            out << append << matrix[i][j]; // Right aligned 
            // out << matrix[i][j] << append;  // Left aligned
        }
        if (i+1 < matrix.columns())
            out << std::endl;
    }

    out << " ]" << std::endl;
    return out;
}

WrapperVector & Matrix::operator[] (unsigned int i) {
    if (i >= num_columns) { 
        throw std::out_of_range("index out of range");
    }
    return (*matrix)[i];
}

WrapperVector Matrix::operator[] (unsigned int i) const {
    if (i >= num_columns) { 
        throw std::out_of_range("index out of range");
    }

    return (*matrix)[i];
}

// 1.3


/*
 * Tilldelningsoperator (english?)
 */
Matrix & Matrix::operator=(const Matrix & copy) {
    if (&(copy.matrix) == &(this->matrix)) {
        return *this;
    }

    delete matrix; // get rid of the data we already have allocated

    num_columns = copy.columns();
    num_rows = copy.rows();

    matrix = new Vector<WrapperVector >(columns());

    // FIXME need fixing in case of more then two dimensions
    for (unsigned int i = 0; i < columns(); i++) {
        for (unsigned int j = 0; j < rows(); j++) {
            (*matrix)[i][j] = copy[i][j];
        }
    }

    return *this;
}

/*
 * Addition
 *
 * the matrices need to be of equal size
 *
 * A new matrix will be returned
 */
Matrix operator+(const Matrix & A, const Matrix & B) {
    if (A.columns() == B.columns() && A.rows() == B.rows()) {
        Matrix C(A.columns(), A.rows());
        for (unsigned int i = 0; i < A.columns(); ++i) {
            for (unsigned int j = 0; j <A.rows(); ++j) {
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        return C;

    }
    else {
        throw WrongSizeException();
    }
}
/*
 * Subtraction
 *
 * The matrices need to be of equal size
 * XXX: Note: could it be implemented with negation and addition? is that easier?
 *
 * A new matrix will be returned
 */
Matrix operator-(const Matrix & A, const Matrix & B) {
    if (A.columns() == B.columns() && A.rows() == B.rows()) {
        Matrix C(A);

        C.negate();

        C = B + C;

        return C;
    
    }
    else {
        throw WrongSizeException();
    }
}

/*
 * Matrix multiplication
 *
 * Only applicable if the number of columns of the left matrix is the same as
 * the number of rows of the right matrix.
 *
 * If matrix A is m*n and B is n*p then A*B is m*p
 *
 * A new matrix will be returned
 *
 * This algorithm runs in O(n^3)
 */
Matrix operator*(const Matrix & A, const Matrix & B) {
    Matrix C(A.columns(), B.rows());

    for (unsigned int i = 0; i < A.columns(); i++) {
        for (unsigned int j = 0; j < A.rows(); ++j) {
            for (unsigned int k = 0; k < A.rows(); ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return C;
}

/*
 * Scalar multiplication
 *
 */
Matrix operator*(const Matrix & A, int n) {
    Matrix C(A);
    for (unsigned int i = 0; i < A.columns(); i++) {
        for (unsigned int j = 0; j < A.rows(); ++j) {
            C[i][j] *= n;
        }
    }
    return C;
}


/*
 * Scalar mutliplication
 */
Matrix operator*(int a, const Matrix & B) {
    return B*a;
}

// other methods

/*
 * Identity
 *
 * If the matrix is square, make the matrix into the identity matrix
 */
void Matrix::identity() {
    // We need square matrices
    if (rows() != columns()) {
        throw WrongSizeException();
    } 
    else {
        for (unsigned int i = 0; i < columns(); i++) {
            for (unsigned int j = 0; j < rows(); ++j) {
                if (i == j)
                    (*matrix)[i][j] = 1;
                else
                    (*matrix)[i][j] = 0;
            }
        }
    }
}

/*
 * Negation
 *
 * Negate every cell in the matrix
 */
void Matrix::negate() {
    for (unsigned int i = 0; i < columns(); i++) {
        for (unsigned int j = 0; j < rows(); ++j) {
            (*matrix)[i][j] *= -1;
        }
    }
}

/*
 * Transpose
 *
 * Turn rows into columns and vice versa
 * Returns a new matrix
 * XXX: might need diffrent return type
 */
void Matrix::transpose() {
    Vector<WrapperVector > * old_matrix = matrix;
    int old_columns = columns();
    int old_rows = rows();

    num_columns = old_rows;
    num_rows = old_columns;

    matrix = new Vector<WrapperVector >(num_columns);

    for (unsigned int i = 0; i < num_columns; ++i) {
        (*matrix)[i].set_size(num_rows);

        for (unsigned int i = 0; i < columns(); ++i) {
            for (unsigned int j = 0; j < rows(); ++j) {
                (*matrix)[i][j] = (*old_matrix)[j][i];
            }
        }
    }

    delete old_matrix;
}
