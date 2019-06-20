CC=clang
EDGES=20000
TIME=/usr/bin/time -a --output target/time.txt -f "%C\nMax MEM %Mkb - %E %es\n"

default: clean target/graph target/graph.jar target/graph.wasm

clean:
	rm -rf target/*
	rm -f src/main/c/data.h
	rm -f time.txt

make-c: src/main/c/data.h
	mkdir -p target
	$(CC) -Wall src/main/c/*.c -o target/graph -O3

make-java: tmp/roadNet-TX.txt
	mkdir -p target/classes
	javac -g -d target/classes src/main/java/*.java
	grep -v \# tmp/roadNet-TX.txt | head -20000 >target/classes/data.txt
	jar cfe target/graph.jar Main -C target/classes .

make-wasm: src/main/c/data.h
	~/dev/wasi-sdk-5.0/opt/wasi-sdk/bin/clang src/main/c/*.c -o target/graph.wasm -O3 --sysroot ~/dev/wasi-sdk-5.0/opt/wasi-sdk/share/sysroot

src/main/c/data.h:
	bash scripts/gen-data.sh $(EDGES)

tmp/roadNet-TX.txt:
	bash scripts/gen-data.sh $(EDGES)

run-c: make-c
	$(TIME) target/graph 1

run-wasm: make-wasm
	$(TIME) wasmer run --backend=llvm --em-entrypoint=main target/graph.wasm 5

run-java: make-java
	$(TIME) java -Xmx4G -Xms1G -jar target/graph.jar $(EDGES) 5

run-all: run-c run-java run-wasm
