#pragma once

#include "./vm.h"

namespace ExVM {
	typedef bool (*Instruction)(VM &vm, unsigned int operand);

	// The integer return value represents if the instruction increments the program counter
	bool inst_noop(VM &vm, unsigned int operand);
	bool inst_ldr(VM &vm, unsigned int operand);
	bool inst_mov(VM &vm, unsigned int operand);
	bool inst_push(VM &vm, unsigned int operand);
	bool inst_pop(VM &vm, unsigned int operand);
	bool inst_call(VM &vm, unsigned int operand);

	const Instruction itable[EXVM_ITABLE_SIZE] = {
		inst_noop, // 0x00
		inst_ldr, // 0x01
		inst_mov, // 0x02
		inst_push, // 0x03
		inst_pop, // 0x04
		inst_call, // 0x05
		inst_noop, // 0x06
		inst_noop  // 0x07
	};
}
