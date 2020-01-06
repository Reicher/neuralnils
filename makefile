CXX=g++
CPPFLAGS=-g -std=c++11
DAEMON=neuralnils
RUNNING=$(shell ps -eo 'pid,comm' | grep $(DAEMON) | grep -o '[0-9]*')

all: test daemon

test: matrix
	$(CXX) $(CPPFLAGS) main.cc -o test matrix.o

daemon: matrix
	$(CXX) $(CPPFLAGS) daemonize.cc -o $(DAEMON) matrix.o

matrix: matrix.cc matrix.h
	$(CXX) $(CPPFLAGS) -c matrix.cc
clean:
	rm -rf *.o *.out test $(DAEMON)
stop:
	kill $(RUNNING)
