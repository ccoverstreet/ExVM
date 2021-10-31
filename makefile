cpp = g++

driver: src/*.cpp
	$(cpp) src/*.cpp -o driver

run: driver
	./driver

mem: driver
	valgrind ./driver -s
