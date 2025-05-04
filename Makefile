#avigezerhalel@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRC = SquareMat.cpp
HEADERS = SquareMat.hpp

Main: $(SRC) main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o Main $(SRC) main.cpp
	./Main

test: $(SRC) test.cpp $(HEADERS) doctest.h
	$(CXX) $(CXXFLAGS) -o test $(SRC) test.cpp
	./test

valgrind: test
	valgrind --leak-check=full ./test

clean:
	rm -f Main test
