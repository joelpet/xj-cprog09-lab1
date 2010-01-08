SHELL=/bin/sh
CC=g++
CDFLAGS=-c -Wall -Wextra
LDFLAGS=
SOURCES=test.cpp Matrix.cpp
# Substitution variable that turns a list of *.cpp to *.o
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)

# $@ expands to the file name of the target
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# Implicit rule (http://www.gnu.org/software/make/manual/make.html#Implicit-Rules)
.cpp.o:
	$(CC) $(CDFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS)

run: all
	./$(EXECUTABLE)

