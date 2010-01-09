#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"
#include "wrapper_vector.h"

class Matrix {
    private:
        Vector<WrapperVector> * matrix;
        int digits(int);
    public:
        const unsigned int num_columns;
        const unsigned int num_rows;
        explicit Matrix(unsigned int x, unsigned int y);
        ~Matrix();
        WrapperVector & operator[] (unsigned int);
        WrapperVector operator[] (unsigned int) const;
};

std::ostream & operator<<(std::ostream & out, const Matrix & matrix);
std::ostream & operator>>(std::ostream & out, const Matrix & matrix);

#endif // header guard
