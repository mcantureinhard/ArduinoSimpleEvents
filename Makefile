.PHONY: all
all: test.cpp
	g++ -Wall -g test.cpp SimpleEvents.cpp -o test
	./test
