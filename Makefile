src = $(filter-out main.cpp, $(wildcard %.cpp))
obj = $(patsubst %.cpp, ./bin/%.o, $(src))
arc = $(patsubst %.cpp, ./lib/lib%.a, $(src))
filename = "rsg"
values = -Wall -I ./includes

ALL: ./build/$(filename)
./build/$(filename): main.cpp $(arc)
	-mkdir build
	g++ $^ -o $@ $(values)
./lib/lib%.cpp: ./bin/%.o
	-mkdir lib
	ar rcs $@ $<
./bin/%.o:./%.cpp
	-mkdir bin
	g++ -c $< -o $@ $(values)

.PHONY: clean
clean:
	-rm ./build/$(filename)
	-rm ./bin/*
	-rm ./lib/*
	-rm -r ./build
	-rm -r ./bin
	-rm -r ./lib

install:
	mv ./build/$(filename) /usr/local/bin/

remove:
	-rm ./build/$(filename) /usr/local/bin/$(filename)
