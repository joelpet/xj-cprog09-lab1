#include <iostream>
#include <sstream>
#include <cxxtest/TestSuite.h>

#include "matrix.h"
#include "wrong_size.h"

class MatrixTestSuite : public CxxTest::TestSuite {
    
    private:

        Matrix * a;
        Matrix * b;
        Matrix * c;

        Matrix * empty1;
        Matrix * empty2;

        Matrix * one;
        Matrix * one2;

        Matrix * A;
        Matrix * B;
        Matrix * C;
        Matrix * D;

    public:

        /**
         * Sets up a test fixture before every test.
         */
        virtual void setUp() { 
            a = new Matrix(7, 4);        // initiering med 7 rader och 4 kolumner med nollor

            b = new Matrix(3, 4);
            int value = -47;
            for (unsigned int col = 0; col < 3; ++col) {
                for (unsigned int row = 0; row < 4; ++row) {
                    (*b)[col][row] = value;
                    value += 17;
                }
            }

            c = new Matrix(100, 100);

            empty1 = new Matrix();
            empty2 = new Matrix();

            one = new Matrix(1,1);
            one2 = new Matrix(1,1);

            A = new Matrix(10,20);
            B = new Matrix(20,10);
            C = new Matrix(10,10);
            D = new Matrix(10,10);

            (*D)[9][9] = 4;
        }

        /**
         * Tears down the earlier set up test fixture.
         */
        virtual void tearDown() { 
            delete a;
            delete b;
            delete c;
            delete empty1;
            delete empty2;
            delete one;
            delete one2;
            delete A;
            delete B;
            delete C;
            delete D;
        }

        void test_direct_access(void) {
            (*a)[5][2] = 7;           // tilldelning till element
            (*c)[3][1] = 4711;
            (*c)[99][99] = 13;
            (*one)[0][0] = 4711;

            // these 2 lines should raise a compile error if uncommented
//            Matrix tmp(*a);
//            tmp[5][2] = 70;

            TS_ASSERT_EQUALS((*a)[5][2], 7);
            TS_ASSERT_EQUALS((*c)[99][99], 13);
            TS_ASSERT_EQUALS((*one)[0][0], 4711);
        }

        /**
         * Tests printing of matrix to standard out on matlab format.
         */
        void test_cout_printing(void) {
            std::stringstream ass;
            ass << (*a);

            std::stringstream bss;
            bss << (*b);

            TS_ASSERT_EQUALS(ass.str(), "[ 0 0 0 0 0 0 0\n; 0 0 0 0 0 0 0\n; 0 0 0 0 0 0 0\n; 0 0 0 0 0 0 0 ]\n");
            TS_ASSERT_EQUALS(bss.str(), "[ -47  21  89\n; -30  38 106\n; -13  55 123\n;   4  72 140 ]\n");
        }

        /**
         * Tests that matrix is reading matlab formatted input from 
         * stdin correctly. The input should be valid.
         */
        void test_cin_reading(void) {
            // empty1
            std::stringstream user_input1("[ 1 2 -3 ; 5 6 7 ]");
            user_input1 >> (*empty1);
            std::ostringstream out1;
            out1 << (*empty1);

            TS_ASSERT_EQUALS((*empty1)[0][0], 1);
            TS_ASSERT_EQUALS((*empty1)[1][0], 2);
            TS_ASSERT_EQUALS((*empty1)[2][0], -3);
            TS_ASSERT_EQUALS((*empty1)[0][1], 5);
            TS_ASSERT_EQUALS((*empty1)[1][1], 6);
            TS_ASSERT_EQUALS((*empty1)[2][1], 7);

            // empty2
            std::stringstream user_input2("[ 1 2 0 ; 2 5 -1 ; 4 10 -1 ]");
            user_input2 >> (*empty2);
            std::ostringstream out2;
            out2 << (*empty2);

            TS_ASSERT_EQUALS((*empty2)[0][0], 1);
            TS_ASSERT_EQUALS((*empty2)[1][0], 2);
            TS_ASSERT_EQUALS((*empty2)[2][0], 0);
            TS_ASSERT_EQUALS((*empty2)[0][1], 2);
            TS_ASSERT_EQUALS((*empty2)[1][1], 5);
            TS_ASSERT_EQUALS((*empty2)[2][1], -1);
            TS_ASSERT_EQUALS((*empty2)[0][2], 4);
            TS_ASSERT_EQUALS((*empty2)[1][2], 10);
            TS_ASSERT_EQUALS((*empty2)[2][2], -1);
        }

        void test_increment_on_specific_element(void) {
            (*c)[0][0]++;

            TS_ASSERT_EQUALS((*c)[0][0], 1);
        }

        void test_illegal_access(void) {
            TS_ASSERT_THROWS((*a)[1][5], std::out_of_range);
            TS_ASSERT_THROWS((*a)[10][1], std::out_of_range);
            TS_ASSERT_THROWS((*a)[10][5], std::out_of_range);
        }


        // Exception throwing
        
        void test_illegal_addition(void) {
            TS_ASSERT_THROWS(*A+*B, WrongSizeException); 
            TS_ASSERT_THROWS(*B+*A, WrongSizeException);
            TS_ASSERT_THROWS(*A+*C, WrongSizeException);
            TS_ASSERT_THROWS(*C+*A, WrongSizeException);
            TS_ASSERT_THROWS(*B+*C, WrongSizeException);
            TS_ASSERT_THROWS(*C+*B, WrongSizeException);
        }

        void test_illegal_subtraction(void) {
            TS_ASSERT_THROWS(*A-*B, WrongSizeException); 
            TS_ASSERT_THROWS(*B-*A, WrongSizeException);
            TS_ASSERT_THROWS(*A-*C, WrongSizeException);
            TS_ASSERT_THROWS(*C-*A, WrongSizeException);
            TS_ASSERT_THROWS(*B-*C, WrongSizeException);
            TS_ASSERT_THROWS(*C-*B, WrongSizeException);
        }

        void test_illegal_identity(void) {
            TS_ASSERT_THROWS(a->identity(), WrongSizeException);
        }

        void test_illegal_matrix_multiplication(void) {
            TS_ASSERT_THROWS((*A) * (*C), WrongSizeException);
            TS_ASSERT_THROWS((*A) * (*A), WrongSizeException);
        }

        void test_assignment_operator(void) {
            (*A)[0][0] = 10;
            (*A) = (*A);
            (*A)[5][5] = 20;

            (*C)[0][0] = 17;
            (*B) = (*C);
            (*B)[0][0] = 99;

            TS_ASSERT_EQUALS((*A)[0][0], 10);
            TS_ASSERT_EQUALS((*A)[5][5], 20);

            TS_ASSERT_EQUALS((*B)[0][0], 99);
            TS_ASSERT_EQUALS((*C)[0][0], 17);
        }

        void test_copy_constructor(void) {
            Matrix copy(*D);

            TS_ASSERT_EQUALS(copy, *D);

            copy[1][1] = 17;
            (*D)[1][1] = 4711;

            TS_ASSERT_DIFFERS(copy, *D);

        }

        void test_comparison_operator(void) {
            TS_ASSERT_EQUALS(*one2, *one);
            TS_ASSERT_DIFFERS(*C, *D);
        }

        void test_addition(void) {
            std::stringstream user_input1("[ 1 0 2 ; -1 3 1 ]");
            user_input1 >> (*A);

            std::stringstream user_input2("[ 1 2 3 ; 4 5 6 ]");
            user_input2 >> (*B);

            std::stringstream user_input3("[ 2 2 5 ; 3 8 7 ]");
            user_input3 >> *C;
            TS_ASSERT_EQUALS(*A + *B, *C);
        }
        
        void test_subtraction(void) {
            std::stringstream user_input1("[ 1 0 2 ; -1 3 1 ]");
            user_input1 >> (*A);

            std::stringstream user_input2("[ 1 2 3 ; 4 5 6 ]");
            user_input2 >> (*B);

            std::stringstream user_input3("[ 0 -2 -1 ; -5 -2 -5 ]");
            user_input3 >> *C;
            TS_ASSERT_EQUALS(*A - *B, *C);
        }

        void test_matrix_multiplication(void) {
            Matrix C(1,1);
            
            C[0][0] = 9;
            (*one)[0][0] = 3;
            TS_ASSERT_EQUALS(C, *one * *one);

            TS_ASSERT_EQUALS(*empty2, *empty1 * *empty2);

            std::stringstream user_input1("[ 1 0 2 ; -1 3 1 ]");
            user_input1 >> (*A);

            std::stringstream user_input2("[ 3 1 ; 2 1 ; 1 0 ]");
            user_input2 >> (*B);

            std::stringstream user_input3("[ 5 1 ; 4 2 ]");
            user_input3 >> C;
            TS_ASSERT_EQUALS(*A * *B, C);
        }

        void test_scalar_multiplication(void) {
            (*one2)[0][0] = 9;
            (*one)[0][0] = 3;
            TS_ASSERT_EQUALS(*one2, *one * 3);

            TS_ASSERT_EQUALS(*a, *a * 5);

            std::stringstream user_input1("[ 5 1 ; 4 2 ]");
            user_input1 >> *A;

            std::stringstream user_input2("[ 65 13 ; 52 26 ]");
            user_input2 >> *C;

            TS_ASSERT_EQUALS(*C, *A * 13);
        }

        void test_identity(void) {
            C->identity();
            std::stringstream ss;
            ss << (*C);

            TS_ASSERT_EQUALS(ss.str(), "[ 1 0 0 0 0 0 0 0 0 0\n; 0 1 0 0 0 0 0 0 0 0\n; 0 0 1 0 0 0 0 0 0 0\n; 0 0 0 1 0 0 0 0 0 0\n; 0 0 0 0 1 0 0 0 0 0\n; 0 0 0 0 0 1 0 0 0 0\n; 0 0 0 0 0 0 1 0 0 0\n; 0 0 0 0 0 0 0 1 0 0\n; 0 0 0 0 0 0 0 0 1 0\n; 0 0 0 0 0 0 0 0 0 1 ]\n");
        }

        void test_negation(void) {
            std::stringstream user_input1("[ 1 0 2 ; -1 3 1 ]");
            user_input1 >> (*A);

            std::stringstream user_input2("[ -1 0 -2 ; 1 -3 -1 ]");
            user_input2 >> (*B);

            A->negate();

            TS_ASSERT_EQUALS(*A, *B);
        }

        void test_transposing(void) {
            std::stringstream test1("[ 4 -21 5 8 7 ; 1 100 7 -50 17 ; 2 9 11 45 4711 ]");
            test1 >> (*A);
            A->transpose();

            Matrix Aref;
            std::stringstream ref1("[ 4 1 2 ; -21 100 9 ; 5 7 11 ; 8 -50 45 ; 7 17 4711 ]");
            ref1 >> Aref;

            TS_ASSERT_EQUALS(*A, Aref);
        }

        void test_chained_operations(void) {
            Matrix m1, m2, m3, m4, m5, result;
            int k = 17;

            std::stringstream ss1("[ -2 5 8 ; -9 -8 6 ; 6 -7 5 ; -3 1 -9 ; 2 -0 -9 ]"); 
            std::stringstream ss2("[ 7 -6 -2 -8 -7 ; 7 1 -6 -8 2 ; -5 3 9 -7 1 ]"); 
            std::stringstream ss3("[ -9 5 9 6 -2 ; 9 -9 10 0 -7 ; 5 7 7 -6 -9 ]"); 
            std::stringstream ss4("[ 9 -3 -9 7 -9 ; -4 -1 7 -3 -6 ; -4 3 1 -1 3 ]"); 
            std::stringstream ss5("[ -8 7 -9 4 ; 6 -3 3 6 ; 8 -4 2 -4 ; 1 5 1 4 ; -8 -10 5 1 ]"); 
            std::stringstream ssr("[ 10415 18586 -22875 -4501 ; -16423 -1122 -5760 11870 ; 31633 -18037 21413 4126 ; -29854 -891 1413 752 ; -13000 -9029 13028 -499 ]"); 

            ss1 >> m1;
            ss2 >> m2;
            ss3 >> m3;
            ss4 >> m4;
            ss5 >> m5;
            ssr >> result;

            TS_ASSERT_EQUALS((m1*(m2+(k*m3)-m4))*m5, result);
        }

        // Mix between 1.1 and 1.3
        void test_mixed_operations(void) {
            Matrix m1, m2, tmp, res;
            std::stringstream ss1("[ 3 3 3 ; 3 3 3 ; 3 3 3 ; 3 3 3 ]"); 
            std::stringstream ss2("[ 1 2 0 ; 1 1 0 ; 2 1 1 ; 3 0 1 ]"); 
            std::stringstream ssr("[ 3 6 0 ; 3 3 0 ; 6 3 3 ; 9 0 3 ]"); 

            ss1 >> m1;
            ss2 >> m2;
            ssr >> res;

            tmp = m1[2][3]*m2;

            TS_ASSERT_EQUALS(tmp, res);
        }
};

