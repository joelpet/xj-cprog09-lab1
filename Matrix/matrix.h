#include "wrapper_vector.h"

class Matrix {
    private:
        Vector<WrapperVector> * matrix;
        int digits(int);
    public:
        // Constructors
        Matrix(unsigned int x, unsigned int y);
        Matrix(const Matrix &); // Copy constructor


        // Variabels
        const unsigned int num_columns;
        const unsigned int num_rows;

        // operators
        WrapperVector & operator[] (int);
        WrapperVector operator[] (int) const;
        Matrix & operator=(const Matrix &);     // Tilldelningsoperator (english?)

        // other methods
        void identity();    // If square, make matrix into identity matrix
        void negate();      // Negate whole matrix
        void transpose();   // Transpose matrix

        
};

std::ostream & operator<<(std::ostream & out, const Matrix & matrix);
Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);
Matrix operator*(int, const Matrix &);                // Scalar multiplication
Matrix operator*(const Matrix &, int );                // Scalar multiplication
