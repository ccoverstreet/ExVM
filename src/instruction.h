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
	bool inst_jr(VM &vm, unsigned int operand);
	bool inst_ja(VM &vm, unsigned int operand);
	bool inst_jnz(VM &vm, unsigned int operand); // Jump not zero
	bool inst_jlt(VM &vm, unsigned int operand); // Jump less than
	bool inst_add(VM &vm, unsigned int operand); // 

	const Instruction itable[EXVM_ITABLE_SIZE] = {
		inst_noop, // 0x00
		inst_ldr, // 0x01
		inst_mov, // 0x02
		inst_push, // 0x03
		inst_pop, // 0x04
		inst_call, // 0x05
		inst_jr, // 0x06
		inst_ja,  // 0x07
		inst_jnz, // 0x08
		inst_jlt, // 0x09
		inst_add, // 0x0a
	};
}
