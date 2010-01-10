#include <cxxtest/TestSuite.h>

#include "matrix.h"

class MatrixTestSuite : public CxxTest::TestSuite {
    
    private:

        Matrix * a;

    public:

        /**
         * Sets up a test fixture before every test.
         */
        virtual void setUp() { 
            a = new Matrix(7, 4);        // initiering med 7 rader och 4 kolumner med nollor
        }

        /**
         * Tears down the earlier set up test fixture.
         */
        virtual void tearDown() { 
            delete a;
        }

        // Att testa:
        // att ett konstant matrisobjekt returnerar skrivskyddat element
        // att matrisen är nollindexerad
        // tilldelning fungerar
        // operator++ på ett element fungerar
        // ogiltig åtkomst inte fungerar


        void test_direct_mutate_access(void) {
            (*a)[5][2] = 7;           // tilldelning till element

            TS_ASSERT_EQUALS((*a)[5][2], 7);
        }

        void test_direct_const_access(void) {
            // int x = matris[7][2]

            TS_WARN("Not yet implemented!");
        }

        void test_cout_printing(void) {
            // std::cout << matris << std::endl;

            TS_WARN("Not yet implemented!");
        }

        void test_cin_reading(void) {
            // Reading user input, which is assumed to be correct
            // >> `[1 2 0; 2 5 -1; 4 10 -1]'

            TS_WARN("Not yet implemented!");
        }

        void test_illegal_access(void) {
            TS_ASSERT_THROWS(a[1][5], std::out_of_range);
//            TS_ASSERT_THROWS(a[10][1], std::out_of_range);
//            TS_ASSERT_THROWS(a[10][5], std::out_of_range);
        }

};

