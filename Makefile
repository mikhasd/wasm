CC=gcc
EDGES=20000

default: clean target/graph target/graph.jar target/graph.wasm

clean:
	rm -rf target/*
	rm -f src/main/c/data.h

target/graph: src/main/c/data.h
	$(CC) -Wall src/main/c/*.c -o target/graph -O3

target/graph.jar: tmp/roadNet-TX.txt
	javac -g -d target/classes src/main/java/*.java
	cp tmp/roadNet-TX.txt target/classes/data.txt
	jar cfe target/graph.jar Main -C target/classes .

target/graph.wasm: src/main/c/data.h
	clang src/main/c/*.c -o target/graph.wasm -O3 --sysroot /home/mikhas/develop/wasi/wasi-sdk-5.0/opt/wasi-sdk/share/sysroot

src/main/c/data.h:
	bash scripts/gen-data.sh $(EDGES)

src/main/resources/roadNet-TX.txt:
	bash scripts/gen-data.sh $(EDGES)

tmp/roadNet-TX.txt:
	bash scripts/gen-data.sh $(EDGES)

run-c: target/graph
	time target/graph

run-wasm: target/graph.wasm
	time wasmer run --em-entrypoint=main target/graph.wasm

run-java: target/graph.jar
	time java -jar target/graph.jar $(EDGES) 5

run-all: run-c run-java run-wasm