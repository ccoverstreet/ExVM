#pragma once

#include <array>
#include <stdio.h>
#include <stdbool.h>

#define EXVM_ITABLE_SIZE 8
#define EXVM_N_REGISTERS 8

namespace ExVM {
	enum Error {
		NONE,
		ERR
	};

	class VM {
		public:
			VM(unsigned int, unsigned int);
			~VM();

			void PrintState();
			void PrintProgram();
			void PrintStack();
			void PrintRegisters();

			Error LoadProgram(unsigned int *data, size_t size);
			
			Error GetProgramValue(unsigned int index, unsigned int &val);

			Error GetRegisterValue(unsigned char reg, unsigned int &val);
			Error SetRegisterValue(unsigned char dest, unsigned int value);

			Error Push(unsigned int val);
			Error Pop(unsigned int &val);

			Error Execute();

			bool flagStop = false;

		private:
			unsigned int m_r[EXVM_N_REGISTERS]; // Registers	
			unsigned int *m_program; // Pointer to block of memory for program
			unsigned int m_programSize;
			unsigned int *m_stack; // Pointer to block of memory for stack
			unsigned int m_stackSize;

			unsigned int m_pc = 0; // Program counter
			int m_sp = -1; // Stack pointer

	};
}
