#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstdio>


// Single Allocation Stack
// Useful for Embedded
class FixedStack {
	public:
		FixedStack() {
			m_stack = NULL;
			m_stackSize = 0;
		}

		FixedStack(uint32_t stack_size) {
			m_stackSize = stack_size;
			m_stack = new uint32_t[stack_size];
			this->clearStack();
		}

		FixedStack(const FixedStack &stack) {
			m_stackSize = stack.m_stackSize;
			m_stack = new uint32_t[m_stackSize];
			m_sp = -1;
		}

		FixedStack& operator=(const FixedStack& orig) {
			m_stack = new uint32_t[orig.m_stackSize];
			m_stackSize = orig.m_stackSize;
			m_sp = -1;

			return *this;
		}
		
		~FixedStack() {
			delete[] m_stack;
		}


		void printStack() {
			for (size_t i = 0; i < m_stackSize; i++) {
				printf("%u: %08x\n", i, m_stack[i]);
			}
		}

		int push(uint32_t val) {
			if ((m_sp + 1) >= m_stackSize) return 1;

			m_sp++;
			m_stack[m_sp] = val;
			return 0;
		}

		int pop(uint32_t &val) {
			if (m_sp <= -1) return 1;
				
			val = m_stack[m_sp];
			m_stack[m_sp] = 0;
			m_sp--;	
			return 0;
		}
		
	private:
		uint32_t *m_stack = NULL;
		uint32_t m_stackSize;
		int m_sp = -1;

		void clearStack() {
			for (size_t i = 0; i < m_stackSize; i++) {
				m_stack[i] = 0;
			}
		}
};
