#pragma once

#include <iostream>
#include <cstdint>
#include <vector>
#include <functional>

#include "./stack.h"


struct Instruction {
	uint8_t code;
	uint32_t operand;
};

class Machine {
	private:
		FixedStack m_stack;
		size_t m_pc = 0;
		//std::vector<Instruction> m_program;

	public:
		Machine(size_t stackSize);
		~Machine();

		void loadProgram(std::vector<Instruction> prog);
		void printStack();

		//void step(std::function<void(Machine&)> &table) {
		//};

		int push(uint32_t val);
		int pop(uint32_t &val);
};


// INSTRUCTIONS
typedef int (*InstFunc)(Machine&);

int noop(Machine &vm){ return 0; }
int addInt(Machine &vm);
int subInt(Machine &vm);

const InstFunc INST_TABLE[3] = {
	noop,
	addInt,
	subInt
};
