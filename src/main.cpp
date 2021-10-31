#include <iostream>
#include <stack>
#include <cstdint>
#include <vector>

#include "./vm.h"



void testMath(Machine &vm) {
	// x = 1 + 2 + 1 - 3

	vm.push(1);
	vm.push(2);
	vm.push(1);
	vm.push(1);
	subInt(vm);
	addInt(vm);
	addInt(vm);
	printf("%u\n", vm.pop());
}



int main() {
	size_t PROGRAM_SIZE = 10;
	std::vector<Instruction> prog = {
		{0x01, 5},
		{0x01, 0x00000001},
		{0x01, 0x00000003},
		{0x04, 0x0},
		{0x03, 0x0}
	};

	Machine vm(20);

	for (size_t i = 0; i < PROGRAM_SIZE; i++) {
		
	}

	printf("%u\n", vm.pop());
	//testMath(vm);

	return 0;
}
