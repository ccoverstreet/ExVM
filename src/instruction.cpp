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
		unsigned char proc_id = operand >> (8 * 2);


		return vm.CallProcedure(proc_id, operand);
	};

	bool inst_jr(VM &vm, unsigned int operand) {
		// Second & third byte is offset	
		short int offset = operand >> (8 * 1);
		printf("Operand: %08x\n", operand);
		printf("JR Offset: %d\n", offset);

		vm.SetProgramCounter(vm.GetProgramCounter() + (offset));
		
		return 1;
	}

	bool inst_ja(VM &vm, unsigned int operand) {
		// All of operand is treated as unsigned int
		vm.SetProgramCounter(operand);

		return 1;
	}

	bool inst_jnz(VM &vm, unsigned int operand) {
		unsigned int val;
		int err = vm.GetRegisterValue(1, val);
		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}

		if (val != 0) {
			return inst_jr(vm, operand);
		}

		return 0;
	}

	bool inst_jlt(VM &vm, unsigned int operand) {
		// 2nd and 3rd byte are offset
		// 4th byte is register to compare R1 against
		
		unsigned char rg = operand & 0x000000ff;
		unsigned int rg_val;
		unsigned int val;
		int err = vm.GetRegisterValue(1, val);
		err += vm.GetRegisterValue(rg, rg_val);

		printf("%u < %u\n", val, rg_val);

		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}

		if (val < rg_val) {
			inst_jr(vm, operand);
			return 1;
		}

		return 0;
	}

	bool inst_add(VM &vm, unsigned operand) {
		unsigned char dest = (operand & 0x00ff0000) >> (8 * 2);
		unsigned char source = (operand & 0x0000ff00) >> (8);

		unsigned int dest_val, source_val;

		int err = vm.GetRegisterValue(dest, dest_val);
		err += vm.GetRegisterValue(source, source_val);
		if (err != 0) {
			vm.flagStop = true;
			return 1;
		}

		vm.SetRegisterValue(dest, dest_val + source_val);

		return 0;
	}
}
