// Virtual Machine
// Cale Overstreet
// Nov. 8, 2021

#pragma once

#include "./stack.h"
#include "./instruction.h"

typedef struct {
	FixedStack *stack;
	Instruction *program;
	size_t pc; // Program Counter
} ExVM;

ExVM *ExVM_create(size_t stack_size, size_t program_size);
void ExVM_destroy(ExVM* vm);

void ExVM_print(ExVM *vm);

int ExVM_push(ExVM* vm, uint32_t val);
int ExVM_pop(ExVM* vm, uint32_t *dest);

int ExVM_step(ExVM *vm);
