#include "./vm.h"

Stack::Stack() {

}

Stack::Stack(size_t size) {
	m_maxSize = size;
}

void Stack::push(uint32_t val) {
	if (m_stack.size() >= m_maxSize) {
		exit(100);
	}

	m_stack.push(val);
}

uint32_t Stack::pop() {
	if (m_stack.size() <= 0) {
		exit(101);
	}
	auto val = m_stack.top();
	m_stack.pop();
	return val;
}



Machine::Machine(size_t stack_size) {
	m_stack = Stack(stack_size);
}

void Machine::loadProgram(std::vector<Instruction> prog) {
	m_program = prog;
}

void Machine::step() {
	switch (prog[i].code) {
		case 0x01: // NO-OP
			this.push(prog[i].operand);
			break;
		case 0x02: // Pop
			this.pop();
			break;
		case 0x03: // Add
			addInt(*this);
			break;
		case 0x04: // Subtract
			subInt(*this);
			break;
		case 0x05: // Jump
			jump(*this);
	}
}

void Machine::push(uint32_t val) {
	m_stack.push(val);
}

uint32_t Machine::pop() {
	return m_stack.pop();
}


void addInt(Machine &vm) {
	auto a = vm.pop();
	auto b = vm.pop();
	vm.push(a + b);
}

void subInt(Machine &vm) {
	auto a = vm.pop();
	auto b = vm.pop();
	vm.push(a - b);
}

void jump(Machine &vm) {

}
