# Makefile

all: statexam stattest

statexam: statexam.o stats.o
	g++ -g -o statexam statexam.o stats.o

stattest: stattest.o stats.o
	g++ -g -o stattest stattest.o stats.o

statexam.o: statexam.cpp
	g++ -c -g statexam.cpp

stattest.o: stattest.cpp
	g++ -c -g stattest.cpp

stats.o: stats.cpp
	g++ -c -g stats.cpp

clean:
	rm -f statexam stattest *.o

