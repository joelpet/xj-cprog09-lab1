#include <cxxtest/TestSuite.h>

#include "matrix.h"
#include "maze.cpp" // should probably be made into a class with header file

class MazeTestSuite : public CxxTest::TestSuite {
    
    private:

        char * small;
        char * medium;
        char * large;

    public:

        /**
         * Sets up a test fixture before every test.
         */
        virtual void setUp() { 
            // setup mazes here
        }

        /**
         * Tears down the earlier set up text fixture.
         */
        virtual void tearDown() { 
            // destruct mazes here
        }


        void test_test(void) {
            // access mazes here
        }

};

