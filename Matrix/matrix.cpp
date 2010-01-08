#include "matrix.h"
#include "math.h"

Matrix::Matrix(unsigned int x, unsigned int y) : 
    num_columns(x), num_rows(y) {
        matrix = new Vector<wrapperVector >(num_columns);

        for (unsigned int i = 0; i < num_columns; ++i) {
            (*matrix)[i].setSize(num_rows);
        }
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

wrapperVector & Matrix::operator[] (int i) {
    return (*matrix)[i];
}

wrapperVector Matrix::operator[] (int i) const {
    return (*matrix)[i];
}
