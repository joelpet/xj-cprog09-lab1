#include "Matrix.h"
// #include "vector.h"

Matrix::Matrix(unsigned int x, unsigned int y) : 
    num_columns(x), num_rows(y) {
        matrix = new Vector<wrapperVector >(num_rows);

        for (unsigned int i = 0; i < num_rows; ++i) {
            (*matrix)[i].setSize(num_columns);
        }
}
