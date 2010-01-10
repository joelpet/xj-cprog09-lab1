#include "matrix.h"
#include "math.h"

Matrix::Matrix() : num_columns(0), num_rows(0) {
    initialize();
}

Matrix::Matrix(unsigned int x, unsigned int y) : 
    num_columns(x), num_rows(y) {
        initialize();
//        matrix = new Vector<WrapperVector >(num_columns);

//        for (unsigned int i = 0; i < num_columns; ++i) {
//            (*matrix)[i].set_size(num_rows);
//        }
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
