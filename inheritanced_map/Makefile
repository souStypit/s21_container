CC = g++
CFLAGS =
CSOURCE = main.cpp

all: build
	# valgrind --tool=memcheck --leak-check=yes './app'
	./app

build: clean
	g++ $(CSOURCE) -o app

clean:
	rm -f *.out

format:
	clang-format -i *.cpp *.hpp

