#include "wrapperVector.h"

class Matrix {
    private:
        unsigned int num_columns;
        unsigned int num_rows;
        Vector<wrapperVector > * matrix;
    public:
        explicit Matrix(unsigned int x, unsigned int y);

};
