# Makefile
# Andy Wu, Chase Alcorn
all: runMovies tests

runMovies: main.o movies.o utility.o
	g++ main.o movies.o utility.o -o runMovies

tests: movies.o utility.o tests.o
	g++ movies.o utility.o tests.o -o tests
  
main.o: main.cpp
	g++ -c -Wall main.cpp

movies.o: movies.cpp movies.h
	g++ -c -Wall movies.cpp

utility.o: utility.cpp utility.h
	g++ -c -Wall utility.cpp
  
tests.o: tests.cpp tests.h
	g++ -c -Wall tests.cpp

clean:
	rm *.o runMovies tests