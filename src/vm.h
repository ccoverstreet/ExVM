#pragma once

#include <iostream>
#include <stack>
#include <cstdint>
#include <vector>

class Stack {
	private:
		size_t m_maxSize;
		std::stack<uint32_t> m_stack;

	public:
		Stack();
		Stack(size_t size);

		void push(uint32_t val);
		uint32_t pop();
};

struct Instruction {
	uint8_t code;
	uint32_t operand;
};

class Machine {
	private:
		Stack m_stack;
		size_t m_pc = 0;
		std::vector<Instruction> m_program;
	public:
		Machine(size_t stack_size);

		void loadProgram(std::vector<Instruction> prog);
		void step();
		void push(uint32_t val);
		uint32_t pop();
};

void addInt(Machine &vm);
void subInt(Machine &vm);
void jump(Machine &vm);
