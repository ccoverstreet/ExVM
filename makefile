cpp = g++

driver: src/*.cpp src/*.h
	$(cpp) src/*.cpp -o driver

run: driver
	./driver

mem: driver
	valgrind ./driver -s
