#include <iostream>
#include <stack>
#include <cstdint>
#include <vector>


// Necessary Defines
#define EXVM_STACK_SIZE 8

#include "./vm.h"


void testMath(Machine &vm) {
	// x = 1 + 2 + 1 - 3

	vm.push(1);
	vm.push(3);
	vm.push(1);
	vm.push(1);

	vm.printStack();
}

int main() {
	size_t PROGRAM_SIZE = 10;
	std::vector<Instruction> prog = {
		{0x01, 5},
		{0x01, 0x00000001},
		{0x01, 0x00000003},
		{0x04, 0x0},
		{0x03, 0x0},
		{0x03, 0x0}
	};

	Machine vm(4);
	vm.push(1);
	vm.push(1);
	vm.push(2);
	addInt(vm);
	vm.printStack();
	subInt(vm);
	vm.printStack();

	return 0;
}
