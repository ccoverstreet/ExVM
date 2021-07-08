#include "./instruction.h"
#include <stdio.h>

namespace ExVM {
	bool inst_noop(VM &vm, unsigned int operand) {
		printf("NOOP: %u\n", operand);
		return 0;
	}

	bool inst_ldr(VM &vm, unsigned int operand) {
		// 2nd byte is destination register
		// 3rd and 4th byte are treated as single unsigned int for mem location
		unsigned char dest = (operand & 0x00ff0000) >> (8 * 2);
		unsigned int source = (operand & 0x0000ffff);

		if (dest >= EXVM_N_REGISTERS) {
			vm.flagStop = true;
			return 1;
		}

		unsigned int mem_val;
		int err = vm.GetProgramValue(source, mem_val);
		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}

		vm.SetRegisterValue(dest, mem_val);

		printf("LDR: %u, %u\n", dest, source);
			
		return 0;
	}

	bool inst_mov(VM &vm, unsigned int operand) {
		unsigned char dest = operand >> (2 * 8);
		unsigned char source = (operand & 0x0000ff00) >> 8;

		unsigned int source_val;
		int err = vm.GetRegisterValue(source, source_val);
		if (err != 0) {
			vm.flagStop = true;
			return false;
		}	

		err = vm.SetRegisterValue(dest, source_val);

		return 0;
	}

	bool inst_push(VM &vm, unsigned int operand) {
		unsigned char source_reg = operand >> (2 * 8);

		unsigned int source_val;
		int err = vm.GetRegisterValue(source_reg, source_val);
		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}

		err = vm.Push(source_val);
		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}

		return 0;
	}

	bool inst_pop(VM &vm, unsigned int operand) {
		unsigned char dest = operand >> (2 * 8);

		unsigned int val;
		int err = vm.Pop(val);
		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}

		err = vm.SetRegisterValue(dest, val);
		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}
		
		return 0;
	};

	bool inst_call(VM &vm, unsigned int operand) {
		vm.SetRegisterValue(0x05, 0xff0000ff);

		return 0;
	};
}
