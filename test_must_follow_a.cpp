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

        char vek2[] = {'b', 'b', 'b', 'a', 'b', 'b'};
        result = must_follow_a(vek2, 3, 'a', 'b');
        TS_ASSERT_EQUALS(result, 2);

        char vek3[] = {'b', 'b', 'b', 'a'};
        result = must_follow_a(vek3, 3, 'a', 'b');
        TS_ASSERT_EQUALS(result, 0);
    }
};
