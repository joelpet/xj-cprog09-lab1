#include "matrix.h"
#include "math.h"

Matrix::Matrix(unsigned int x, unsigned int y) : 
    num_columns(x), num_rows(y) {
        matrix = new Vector<WrapperVector >(num_columns);

        for (unsigned int i = 0; i < num_columns; ++i) {
            (*matrix)[i].set_size(num_rows);
        }
}

// Operators

std::ostream & operator<<(std::ostream & out, const Matrix & matrix) {
    int maxDigit = 0;
    int n;
    for (unsigned int i = 0; i < matrix.num_columns; ++i) {
        for (unsigned int j = 0; j < matrix.num_rows; j++) {
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

    for (unsigned int i = 0; i < matrix.num_columns; ++i) {
        if (i != 0)
            out << "; ";
        for (unsigned int j = 0; j < matrix.num_rows; j++) {
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
        if (i+1 < matrix.num_columns)
            out << std::endl;
    }

    out << " ]" << std::endl;
    return out;
}


WrapperVector & Matrix::operator[] (int i) {
    return (*matrix)[i];
}

WrapperVector Matrix::operator[] (int i) const {
    return (*matrix)[i];
}

// 1.3


/*
 * Tilldelningsoperator (english?)
 */
Matrix & Matrix::operator=(const Matrix &) {
    // Fulhack för att börja kompilera, ta bort sen
    Matrix * B = new Matrix(0,0);
    return *B;
}

/*
 * Addition
 *
 * the matrices need to be of equal size
 *
 * A new matrix will be returned
 */
Matrix operator+(const Matrix &, const Matrix &) {
    return Matrix(0,0);
}
/*
 * Subtraction
 *
 * The matrices need to be of equal size
 * XXX: Note: could it be implemented with negation and addition? is that easier?
 *
 * A new matrix will be returned
 */
Matrix operator-(const Matrix &, const Matrix &) {
    return Matrix(0,0);
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
 */
Matrix operator*(const Matrix &, const Matrix &) {
    return Matrix(0,0);
}

/*
 * Scalar multiplication
 *
 */
Matrix operator*(const Matrix &, int) {
    return Matrix(0,0);
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
void Matrix::identity() {}

/*
 * Negation
 *
 * Negate every cell in the matrix
 */
void Matrix::negate() {}  

/*
 * Transpose
 *
 * Turn rows into columns and vice versa
 * Returns a new matrix
 * XXX: might need diffrent return type
 */
void Matrix::transpose() {}
