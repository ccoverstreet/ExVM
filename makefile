SOURCES = src/*.c 
HEADERS = src/*.h

driver: main.c $(SOURCES) $(HEADERS)
	gcc main.c $(SOURCES) -o driver

run: driver
	./driver

memcheck: driver
	valgrind ./driver

tester: tests/tester.c src/stack.c src/vm.c
	gcc tests/tester.c src/stack.c src/vm.c -o tester

test: tester
	valgrind ./tester
