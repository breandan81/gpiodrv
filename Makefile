
CC=gcc
CXX=g++
CFLAGS=-I.
CXXFLAGS=-I.
DEPS=helloworld.h gpio.h
OBJ=helloworld.o gpio.o

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
		$(CXX) -c -o $@ $< $(CXXFLAGS)

helloworld: $(OBJ)
		$(CXX) -o $@ $^ $(CXXFLAGS)

