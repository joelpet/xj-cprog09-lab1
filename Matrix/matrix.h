#include "wrapperVector.h"

class Matrix {
    private:
        Vector<wrapperVector > * matrix;
        int digits(int);
    public:
        const unsigned int num_columns;
        const unsigned int num_rows;
        explicit Matrix(unsigned int x, unsigned int y);
        wrapperVector & operator[] (int);
        wrapperVector operator[] (int) const;
};

std::ostream & operator<<(std::ostream & out, const Matrix & matrix);
