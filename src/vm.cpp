#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <cstring>

#include "./vm.h"
#include "./instruction.h"


namespace ExVM {
	VM::VM(unsigned int programSize, unsigned int stackSize) {
		m_programSize = programSize;
		m_stackSize = stackSize;

		m_program = (unsigned int*)calloc(programSize, sizeof(unsigned int));
		m_stack = (unsigned int*)calloc(stackSize, sizeof(unsigned int));
	}

	VM::~VM() {
		free(m_program);
		free(m_stack);
	}

	void VM::PrintState() {
		printf("SP: %u\n", m_sp);
		printf("Registers:\n");
		for (int i = 0; i < 8; i++) {
			printf("\tr%d: %u\n", i, m_r[i]);
		}

		printf("\nStack\n");
		for (int i = 0; i < m_stackSize; i++) {
			printf("\t%d: %u\n", i, m_stack[i]);
		}
	}

	void VM::PrintProgram() {
		for (int i = 0; i < m_programSize; i++) {
			printf("%d: %u\n", i ,m_program[i]);
		}
	}

	void VM::PrintStack() {
		printf("Stack:\n");
		for (int i = 0; i < m_stackSize; i++) {
			printf("\t%d: %08x\n", i, m_stack[i]);
		}
	}

	void VM::PrintRegisters() {
		printf("Registers:\n");
		for (int i = 0; i < EXVM_N_REGISTERS; i++) {
			printf("\t%d: %08x\n", i, m_r[i]);
		}
	}

	Error VM::LoadProgram(unsigned int *data, size_t size)	{
		if (size > (sizeof(unsigned int) * m_programSize)) {
			return ERR;
		}
		memcpy((void*)m_program, (void*)data, size);

		m_pc = m_program[0];
		return NONE;
	}

	Error VM::GetProgramValue(unsigned int index, unsigned int &val) {
		if (index >= m_programSize) {
			return ERR;
		}

		val = m_program[index];
		return NONE;
	}

	Error VM::SetRegisterValue(unsigned char dest, unsigned int value) {
		m_r[dest] = value;

		return NONE;
	}
	
	Error VM::GetRegisterValue(unsigned char reg, unsigned int &val) {
		if (reg >= EXVM_N_REGISTERS) {
			return ERR;
		}

		val = m_r[reg];

		return NONE;
	}

	Error VM::Push(unsigned int val) {
		m_sp++;
		if (m_sp >= m_stackSize) {
			return ERR;
		}

		m_stack[m_sp] = val;

		return NONE;
	}

	Error VM::Pop(unsigned int &val) {
		if (m_sp < 0) {
			return ERR;
		}

		val = m_stack[m_sp];
		m_sp--;

		return NONE;
	}

	Error VM::Execute() {
		if (flagStop) {
			printf("STOP FLAG\n");
			exit(0);
		}


		printf("PC: %d\n", m_pc);
		// First check if program counter is within program memory
		if (m_pc >= m_programSize) {
			return ERR;	
		}

		printf("%08x\n", m_program[m_pc]);
		unsigned char inst_code = (m_program[m_pc]) >> (8 * 3);
		unsigned int operand = (m_program[m_pc] & 0x00ffffff);


		// Check if instruction code is valid
		if (inst_code >= EXVM_ITABLE_SIZE) {
			return ERR;
		}

		int hasIncremented = itable[inst_code](*this, operand);

		if (!hasIncremented) {
			m_pc += 1;
		}
	
		return NONE;
	}
}
