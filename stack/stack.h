#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <array>

// No allocation stack
// Usedful for embedded environments
template<size_t Size>
class StaticStack {
	public:
		StaticStack(){
			for (auto &elem : m_stack) {
				elem = 0;
			}
		}

		void printStack() {
			for (size_t i = 0; i < m_stack.size(); i++) {
				printf("%u: %08x\n", i, m_stack[i]);
			}
		}

		// push returns 0 if no error
		// push returns  1 if fail
		int push(uint32_t val) {
			if ((m_sp + 1) >= m_stack.size()) {
				return 1;
			}

			m_sp += 1;

			m_stack[m_sp] = val;
			return 0;
		}

		int pop(uint32_t &dest) {
			if (m_sp < 0) {
				return 1;
			}

			dest = m_stack[m_sp];
			m_stack[m_sp] = 0;
			m_sp = m_sp - 1;
			return 0;
		}

	private:
		std::array<uint32_t, Size> m_stack;
		int m_sp = -1; // Stack pointer;
};
