#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"
#include "wrapper_vector.h"

class Matrix {

    private:
        // Variabels
        unsigned int num_columns;       // cannot be const, needs to be changable in copy constructor
        unsigned int num_rows;

        Vector<WrapperVector> * matrix;
        int digits(int);

        void initialize();

    public:
        // Constructors
        Matrix();
        Matrix(unsigned int x, unsigned int y);
        Matrix(const Matrix &); // Copy constructor
        ~Matrix();

        // operators
        WrapperVector & operator[] (unsigned int);
        const WrapperVector & operator[] (unsigned int) const;
        Matrix & operator=(const Matrix &);     // Tilldelningsoperator (english?)

        // other methods
        unsigned int columns() const;
        unsigned int rows() const;
        
        void identity();    // If square, make matrix into identity matrix
        void negate();      // Negate whole matrix
        void transpose();   // Transpose matrix

        void set_dimensions(unsigned int, unsigned int);
        
};

std::ostream & operator<<(std::ostream & out, const Matrix & matrix);
std::istream & operator>>(std::istream & in, Matrix & matrix);
Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);
Matrix operator*(int, const Matrix &);                // Scalar multiplication
Matrix operator*(const Matrix &, int );                // Scalar multiplication
bool operator==(const Matrix &, const Matrix &);

#endif // header guard
