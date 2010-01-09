/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "matrix_test_suite.h"

static MatrixTestSuite suite_MatrixTestSuite;

static CxxTest::List Tests_MatrixTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MatrixTestSuite( "matrix_test_suite.h", 5, "MatrixTestSuite", suite_MatrixTestSuite, Tests_MatrixTestSuite );

static class TestDescription_MatrixTestSuite_test_test : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_test() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 36, "test_test" ) {}
 void runTest() { suite_MatrixTestSuite.test_test(); }
} testDescription_MatrixTestSuite_test_test;

static class TestDescription_MatrixTestSuite_test_direct_access : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_direct_access() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 40, "test_direct_access" ) {}
 void runTest() { suite_MatrixTestSuite.test_direct_access(); }
} testDescription_MatrixTestSuite_test_direct_access;

#include <cxxtest/Root.cpp>
