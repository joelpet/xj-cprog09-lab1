/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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
CxxTest::StaticSuiteDescription suiteDescription_MatrixTestSuite( "matrix_test_suite.h", 7, "MatrixTestSuite", suite_MatrixTestSuite, Tests_MatrixTestSuite );

static class TestDescription_MatrixTestSuite_test_direct_mutate_access : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_direct_mutate_access() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 40, "test_direct_mutate_access" ) {}
 void runTest() { suite_MatrixTestSuite.test_direct_mutate_access(); }
} testDescription_MatrixTestSuite_test_direct_mutate_access;

static class TestDescription_MatrixTestSuite_test_direct_const_access : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_direct_const_access() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 46, "test_direct_const_access" ) {}
 void runTest() { suite_MatrixTestSuite.test_direct_const_access(); }
} testDescription_MatrixTestSuite_test_direct_const_access;

static class TestDescription_MatrixTestSuite_test_cout_printing : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_cout_printing() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 52, "test_cout_printing" ) {}
 void runTest() { suite_MatrixTestSuite.test_cout_printing(); }
} testDescription_MatrixTestSuite_test_cout_printing;

static class TestDescription_MatrixTestSuite_test_cin_reading : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_cin_reading() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 62, "test_cin_reading" ) {}
 void runTest() { suite_MatrixTestSuite.test_cin_reading(); }
} testDescription_MatrixTestSuite_test_cin_reading;

static class TestDescription_MatrixTestSuite_test_increment_on_specific_element : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_increment_on_specific_element() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 76, "test_increment_on_specific_element" ) {}
 void runTest() { suite_MatrixTestSuite.test_increment_on_specific_element(); }
} testDescription_MatrixTestSuite_test_increment_on_specific_element;

static class TestDescription_MatrixTestSuite_test_illegal_access : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_test_illegal_access() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 80, "test_illegal_access" ) {}
 void runTest() { suite_MatrixTestSuite.test_illegal_access(); }
} testDescription_MatrixTestSuite_test_illegal_access;

#include <cxxtest/Root.cpp>
