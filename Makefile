CC=gcc

default: graph

graph:
	$(CC) -Wall src/main/c/*.c -o target/graph
	target/graph