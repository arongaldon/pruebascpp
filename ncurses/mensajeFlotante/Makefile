# This file was create by hand to compile the project in this folder.
# As the project grows, using CMake will be recomended

# Declaration of variables
CC = g++
CXXFLAGS = -w -std=c++17
 
# File names
EXEC = mensaje
SOURCES = $(wildcard *.cpp)
OBJECTS = main.o

LIBS = -lncurses

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(OBJECTS) $(LIBS)
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
