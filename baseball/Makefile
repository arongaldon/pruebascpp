# Declaration of variables
CC = g++
CXXFLAGS = -w -std=c++17
 
# File names
SOURCES = $(wildcard *.cpp)
OBJECTS = main.o BaseballPlayer.o Person.o 
EXEC = baseball

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)
 
# To obtain object files
Person.o : Person.h
BaseballPlayer.o : BaseballPlayer.h #Person.h

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
