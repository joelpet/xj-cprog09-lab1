#include "wrapper_vector.h"

class Matrix {
    private:
        // Variabels
        unsigned int num_columns;       // cannot be const, needs to be changable in copy constructor
        unsigned int num_rows;

        Vector<WrapperVector> * matrix;
        int digits(int);
        
    public:
        // Constructors
        Matrix(unsigned int x, unsigned int y);
        Matrix(const Matrix &); // Copy constructor



        // operators
        WrapperVector & operator[] (int);
        WrapperVector operator[] (int) const;
        Matrix & operator=(const Matrix &);     // Tilldelningsoperator (english?)

        // other methods
        unsigned int columns() const;
        unsigned int rows() const;
        
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
