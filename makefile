cpp = g++


SOURCES = src/*.cpp
TESTS = tests/*

driver: $(SOURCES) src/*.h
	$(cpp) src/main.cpp src/vm.cpp -o driver

run: driver
	./driver

mem: driver
	valgrind ./driver -s

test_driver: $(TESTS) $(SOURCES)
	g++ $(TESTS) -o test_driver

stack_test: src/stack.h tests/stacktest.cpp
	g++ tests/stacktest.cpp -o stack_test

test_stack: stack_test
	./stack_test
