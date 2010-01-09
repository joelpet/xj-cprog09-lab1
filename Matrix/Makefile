##################################################
## Configuration
## =============

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

# Setup binary files directory
bin_dir=bin

# Source files to compile and link together
sources=test.cpp matrix.cpp
objects=$(addprefix $(bin_dir)/,$(sources:.cpp=.o))
executable=$(bin_dir)/test

maze_sources=matrix.cpp maze.cpp
maze_objects=$(addprefix $(bin_dir)/,$(maze_sources:.cpp=.o))
maze_exe=$(bin_dir)/maze


##################################################
## Targets
## =======

all: $(bin_dir) $(sources) $(executable) $(maze_sources) $(maze_exe)

$(bin_dir):
	-mkdir $(bin_dir)

$(executable): $(objects)
	$(CXX) $(LDFLAGS) $(objects) -o $@		

$(maze_exe): $(maze_objects)
	$(CXX) $(LDFLAGS) $(maze_objects) -o $@

$(bin_dir)/%.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $(all_cxxflags) $< -o $@

clean:
	-rm -f $(objects) $(maze_objects)

run: all
	./$(executable)

run_maze: maze
	./$(maze_exe)


##################################################
## Notes
## =====

# $@ expands to the file name of the target

