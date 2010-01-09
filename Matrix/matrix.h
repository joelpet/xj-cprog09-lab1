#include "wrapper_vector.h"

class Matrix {
    private:
        Vector<WrapperVector> * matrix;
        int digits(int);
    public:
        const unsigned int num_columns;
        const unsigned int num_rows;
        explicit Matrix(unsigned int x, unsigned int y);
        WrapperVector & operator[] (int);
        WrapperVector operator[] (int) const;
};

std::ostream & operator<<(std::ostream & out, const Matrix & matrix);
