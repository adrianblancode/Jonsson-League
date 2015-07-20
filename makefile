CC=g++
CDFLAGS= -std=c++11 -g -c -Wall
LDFLAGS=
SOURCES=characters/character.cpp characters/jonsson.cpp characters/king.cpp characters/spider.cpp world.cpp inventory.cpp container.cpp environments/environment.cpp environments/spiderroom.cpp environments/throneroom.cpp item.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o) # Substitution variable that turns a list of *.cpp to *.o
EXECUTABLE=jonsson_league

all: $(SOURCES) $(EXECUTABLE)

# $@ expands to the file name of the target
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CDFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXECUTABLE)

run: all
	./$(EXECUTABLE)
