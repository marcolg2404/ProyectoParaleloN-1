CXX = g++
CXXFLAGS = -g3 -Wall
MKDIR = mkdir -p

LIBS=-lm

directorios: 
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

Clases.o: directorios Clases.cpp Clases.h
	$(CXX) $(CXXFLAGS) -c Clases.cpp -o build/Clases.o

funciones.o: directorios funciones.cpp funciones.h
	$(CXX) $(CXXFLAGS) -c funciones.cpp -o build/funciones.o

all: clean main.o Clases.o funciones.o
	$(CXX) $(CXXFLAGS) $(LIBS) -o dist/programa build/main.o build/Clases.o build/funciones.o
	rm -fr build

clean:
	rm -fr *.o a.out programa dist build

.DEFAULT_GOAL := all
