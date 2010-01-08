#include <cxxtest/TestSuite.h>

#include "must_follow_a.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:
    void test_a_is_second_to_last( void )
    {
        char vek[] = {'x', 'x', 'a', 'b', 'x'};
        int result = must_follow_a(vek, 4, 'a', 'b');
        TS_ASSERT_EQUALS( result, 1);
    }
    void test_a_is_third_to_last(void) {

        char vek2[] = {'b', 'b', 'b', 'a', 'b', 'b'};
        int result = must_follow_a(vek2, 3, 'a', 'b');
        TS_ASSERT_EQUALS(result, 1);
    }

    void test_a_is_last(void) {

        char vek3[] = {'b', 'b', 'b', 'a'};
        int result = must_follow_a(vek3, 3, 'a', 'b');
        TS_ASSERT_EQUALS(result, 0);
    }
    void test_a_is_first(void) {

        char vek3[] = {'b', 'b', 'b', 'a'};
        int result = must_follow_a(vek3, 0, 'b', 'b');
        TS_ASSERT_EQUALS(result, 2);
    }
};
