#Makefile
all: main

main: main.cpp
	g++ -o add-nbo main.cpp

clean:
	rm -f add-nbo
