#include <iostream>
#include <sstream>
#include <cxxtest/TestSuite.h>

#include "matrix.h"
#include "wrong_size.h"

class MatrixTestSuite : public CxxTest::TestSuite {
    
    private:

        Matrix * a;
        Matrix * empty1;
        Matrix * empty2;
        Matrix * one;
        Matrix * one2;

        Matrix * A;
        Matrix * B;
        Matrix * C;

    public:

        /**
         * Sets up a test fixture before every test.
         */
        virtual void setUp() { 
            a = new Matrix(7, 4);        // initiering med 7 rader och 4 kolumner med nollor
            empty1 = new Matrix();
            empty2 = new Matrix();

            one = new Matrix(1,1);
            one2 = new Matrix(1,1);

            A = new Matrix(10,20);
            B = new Matrix(20,10);
            C = new Matrix(10,10);
        }

        /**
         * Tears down the earlier set up test fixture.
         */
        virtual void tearDown() { 
            delete a;
            delete empty1;
            delete empty2;
            delete one;
            delete one2;
            delete A;
            delete B;
            delete C;
        }

        // Att testa:
        // att ett konstant matrisobjekt returnerar skrivskyddat element
        // att matrisen är nollindexerad
        // tilldelning fungerar

        void test_direct_mutate_access(void) {
            (*a)[5][2] = 7;           // tilldelning till element

            TS_ASSERT_EQUALS((*a)[5][2], 7);

            (*one)[0][0] = 4711;

            TS_ASSERT_EQUALS((*one)[0][0], 4711);
        }

        void test_direct_const_access(void) {
            // int x = matris[7][2]

            TS_WARN("Not yet implemented!");
        }

        void test_cout_printing(void) {
            // std::cout << matris << std::endl;

            TS_WARN("Not yet implemented!");
        }

        /**
         * Tests that matrix is reading matlab formatted input from 
         * stdin correctly. The input should be valid.
         */
        void test_cin_reading(void) {

            std::stringstream user_input1("[ 1 2 -3 ; 5 6 7 ]");
            user_input1 >> (*empty1);
//            std::string out;
//            (*empty1) >> out;

//            std::stringstream user_input2("[ 1 2 0 ; 2 5 -1 ; 4 10 -1 ]");
//            user_input2 >> (*empty2);

            TS_ASSERT_EQUALS("", "[ 1 2 -3\n; 5 6 7 ]");
//            TS_ASSERT_EQUALS((*empty2), "[ 1 2 0\n; 2 5 -1\n; 4 10 -1 ]");
        }

        void test_increment_on_specific_element(void) {

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

        void test_comparison_operator(void) {
            TS_ASSERT_EQUALS(*one2, *one);
        }

        void test_matrix_multiplication(void) {
            // Matrix C(1,1);
            // 
            // C[0][0] = 9;
            // (*one)[0][0] = 3;
            // std::cout << "testing one * one " << std::endl;
            // TS_ASSERT_EQUALS(C, *one * *one);
// 
            // std::cout << "testing empty*empty" << std::endl;
            // TS_ASSERT_EQUALS(*empty2, *empty1 * *empty2);
        }

        void test_scalar_multiplication(void) {

            // std::cout << "testing one * 3" << std::endl;
// 
            // (*one2)[0][0] = 9;
            // (*one)[0][0] = 3;
            // // Matrix C(1,1);
            // // C[0][0] = 9;
            // TS_ASSERT_EQUALS(*one2, *one * 3);
            // std::cout << "done with assert" << std::endl;
        }
};

