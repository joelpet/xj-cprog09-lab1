##################################################
## General configuration
## =====================

# Every Makefile should contain this line:
SHELL=/bin/sh

# Program for compiling C++ programs; default `g++'. 
CXX=g++

# Extra flags to give to the C preprocessor and programs that use it (the C and Fortran compilers). 
CPPFLAGS=

# Extra flags to give to the C++ compiler (both at compiling and linking)
# Notice: `make CXXFLAGS='-g -O' will replace the value of CXXFLAGS given below
CXXFLAGS=-Wall -Wextra

# Add any custom flags before $(CXXFLAGS) below, that are required for this build
all_cxxflags=-I.. $(CXXFLAGS)

# Extra flags to give to compilers when they are supposed to invoke the linker, `ld'. 
LDFLAGS=

# CxxTest: If you want to use python, specify USE_PYTHON=1 on the command line
ifdef USE_PYTHON
	testgen=../cxxtestgen.py
else
	testgen=../cxxtestgen.pl
endif


##################################################
## Setup files variables
## =====================

# Setup binary files directory
bin_dir=bin

# Source files to compile and link together
sources=matrix.cpp maze.cpp
objects=$(addprefix $(bin_dir)/,$(sources:.cpp=.o))
executable=$(bin_dir)/maze

# Add test suites here in `tests' variable
tests=matrix_test_suite.h

# CxxTest tests runner output (no need to edit)
tests_runner_cxx=tests_runner.cpp
tests_runner_obj=$(bin_dir)/tests_runner.o
tests_runner_exe=$(bin_dir)/tests_runner



##################################################
## Ordinary targets
## ================

all: $(bin_dir) $(sources) $(executable)

tests: clean $(bin_dir) $(tests) $(tests_runner_exe)

$(bin_dir):
	-mkdir $(bin_dir)

$(executable): $(objects)
	$(CXX) $(LDFLAGS) $^ -o $@		

$(bin_dir)/%.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $(all_cxxflags) $< -o $@

clean:
	-rm -f $(objects) $(tests_runner_obj)

run: all
	./$(executable)

run_tests: tests
	./$(tests_runner_exe)

$(tests_runner_exe): $(tests_runner_obj) $(bin_dir)/matrix.o
	$(CXX) $(LDFLAGS) $^ -o $@		

$(tests_runner_cxx): $(tests)
	$(testgen) -o $@ --error-printer $^


##################################################
## Notes
## =====

# $@ expands to the file name of the target

