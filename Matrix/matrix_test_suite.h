#include <cxx/TestSuite.h>

class MatrixTestSuite : public CxxTest::TestSuite {
    
    private:
        int * test;


    public:

        /**
         * Sets up a test fixture before every test.
         */
        virtual void setUp() { 
            *test = 4711;
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

};

