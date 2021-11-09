
#include "./vm.h"

Machine::Machine(size_t stackSize) {
	m_stack = FixedStack(stackSize);
}

Machine::~Machine() {}

void Machine::printStack() {
	m_stack.printStack();
}

int Machine::pop(uint32_t &val) {
	return m_stack.pop(val);
} 

int Machine::push(uint32_t val) {
	return m_stack.push(val);
} 


// INSTRUCTIONS
int addInt(Machine &vm) {
	uint32_t a, b;
	if (vm.pop(a) || vm.pop(b)) return 1;
	
	vm.push(a + b);
	return 0;
}

int subInt(Machine &vm) {
	uint32_t a, b;
	if (vm.pop(a) || vm.pop(b)) return 1;
	
	vm.push(a - b);
	return 0;
}
