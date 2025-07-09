CXX=g++
CXXFLAGS=-std=c++17 -Wall
LDFLAGS=

.PHONY: all clean

all: manager

manager: main.o vault.o 
	${CXX} ${LDFLAGS} $^ -o manager

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

vault.o: vault.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f *.o manager