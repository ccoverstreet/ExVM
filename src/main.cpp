#include "./vm.h"
#include <unistd.h>

unsigned int test_program[16] = {
	0x00000003,
	0x00000003,
	0x00000001,
	0x01020001,
	0x01030002,
	0x05000100,
	0x03000000,
	0x03000000,
	0x0a010300,
	0x09fffa02
};

bool proc_sleep(ExVM::VM &vm, unsigned int operand) {
	unsigned char sleep_time = operand >> (8 * 1);

	sleep(sleep_time);

	return 0;
}


int main() {
	ExVM::VM vm(16, 8);

	ExVM::Error err = vm.LoadProgram(test_program, sizeof(test_program));
	if (err != 0) {
		return 1;
	}

	err = vm.RegisterProcedure(0, proc_sleep);
	if (err != 0) {
		return 1;
	}

	while(vm.Execute() == 0) {}
	vm.PrintStack();
	vm.PrintRegisters();

	return 0;
}
