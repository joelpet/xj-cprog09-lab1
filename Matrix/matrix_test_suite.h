#include <cxxtest/TestSuite.h>

#include "matrix.h"

class MatrixTestSuite : public CxxTest::TestSuite {
    
    private:

        int * test;
        Matrix * a;

    public:

        /**
         * Sets up a test fixture before every test.
         */
        virtual void setUp() { 
            test = new int(4711);
        }

        /**
         * Tears down the earlier set up text fixture.
         */
        virtual void tearDown() { 
            delete test;
        }
        
        void test_test(void) {
            TS_ASSERT_EQUALS(*test, 4711);
        }

        void test_direct_access(void) {
            TS_WARN("Empty test case to be implemented");
        }

};

