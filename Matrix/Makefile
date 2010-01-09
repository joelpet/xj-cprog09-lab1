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
all_cxxflags=$(CXXFLAGS)

# Extra flags to give to compilers when they are supposed to invoke the linker, `ld'. 
LDFLAGS=

# Source files to compile and link together
sources=test.cpp matrix.cpp

# Substitution variable that turns a list of *.cpp to $(bin_dir)/*.o
bin_dir=bin
objects=$(addprefix $(bin_dir)/,$(sources:.cpp=.o))
executable=$(bin_dir)/test

all: $(bin_dir) $(sources) $(executable)

# Make sure the bin dir exists
$(bin_dir):
	-mkdir $(bin_dir)

# $@ expands to the file name of the target
$(executable): $(objects)
	$(CXX) $(LDFLAGS) $(objects) -o $@

# Implicit rule (http://www.gnu.org/software/make/manual/make.html#Implicit-Rules)
$(bin_dir)/%.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $(all_cxxflags) $< -o $@

clean:
	-rm -f $(objects)

run: all
	./$(executable)

