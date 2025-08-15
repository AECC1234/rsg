src = $(filter-out main.cpp, $(wildcard %.cpp))
obj = $(patsubst %.cpp, ./bin/%.o, $(src))
arc = $(patsubst %.cpp, ./lib/lib%.a, $(src))
filename = "rsg"

ALL: ./build/$(filename)
./build/$(filename): main.cpp $(arc)
	g++ $^ -o $@ -I ./includes -g -Wall
./lib/lib%.cpp: ./bin/%.o
	ar rcs $@ $<
./bin/%.o:./%.cpp
	g++ -c $< -o $@ -I ./includes -g -Wall

.PHONY: clean
clean:
	-rm ./build/$(filename)
	-rm ./bin/*
	-rm ./lib/*

install:
	mv ./build/$(filename) /usr/local/bin/

remove:
	-rm ./build/$(filename) /usr/local/bin/$(filename)
