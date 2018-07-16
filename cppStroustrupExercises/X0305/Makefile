CC = g++
CXXFLAGS = -w -std=c++17

SOURCES = $(wildcard *.cpp)
OBJECTS = main.o
EXEC = a.out

$(EXEC): $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

clean:
	rm -f $(EXEC) $(OBJECTS)
