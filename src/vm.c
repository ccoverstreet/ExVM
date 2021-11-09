// VM Implementation

#include "./vm.h"

ExVM *ExVM_create(size_t stack_size, size_t program_size) {
	ExVM* vm = malloc(sizeof(ExVM));
	vm->program = calloc(sizeof(Instruction), program_size);
	vm->stack = FixedStack_create(stack_size);
	vm->pc = 0;

	return vm;
}

void ExVM_destroy(ExVM *vm) {
	FixedStack_destroy(vm->stack);
	free(vm->program);
	free(vm);
}

void ExVM_print(ExVM *vm) {
	FixedStack_print(vm->stack);
}

int ExVM_push(ExVM* vm, uint32_t val) {
	return FixedStack_push(vm->stack, val);
}

int ExVM_pop(ExVM* vm, uint32_t *dest) {
	return FixedStack_pop(vm->stack, dest);
}

int ExVM_step(ExVM *vm) {

}
