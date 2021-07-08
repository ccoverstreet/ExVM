#include "./vm.h"
#include <unistd.h>

unsigned int test_program[16] = {
	0x00000002,
	0x000000ff,
	0x01000001,
	0x03000000,
	0x03000000,
	0x03000000,
	0x03000000,
	0x03000000,
	0x03000000,
	0x03000000,
	0x04030000,
	0x05000000
};

int main() {
	ExVM::VM vm(16, 8);

	ExVM::Error err = vm.LoadProgram(test_program, sizeof(test_program));
	if (err != 0) {
		return 1;
	}

	while(vm.Execute() == 0) {}
	vm.PrintStack();
	vm.PrintRegisters();

	return 0;
}
