// FixedStack Implementation
// Cale Overstreet
// Nov. 8, 2021

#include "./stack.h"

FixedStack *FixedStack_create(uint32_t stack_size) {
	FixedStack *new_stack = malloc(sizeof(FixedStack));
	new_stack->stack = calloc(sizeof(uint32_t), stack_size);
	new_stack->size = stack_size;
	new_stack->sp = -1;
	return new_stack;
}

void FixedStack_destroy(FixedStack *stack) {
	free(stack->stack);
	free(stack);
}

void FixedStack_print(FixedStack *stack) {
	for (size_t i = 0; i < stack->size; i++) {
		printf("%u: %08x\n", i, stack->stack[i]);
	}
}

int FixedStack_push(FixedStack *stack, uint32_t val) {
	if ((stack->sp + 1) >= stack->size) return 1;

	stack->sp++;
	stack->stack[stack->sp] = val;
	return 0;
}

int FixedStack_pop(FixedStack *stack, uint32_t *dest) {
	if (stack->sp < 0) return 1;
	
	*dest = stack->stack[stack->sp];
	stack->stack[stack->sp] = 0;
	stack->sp--;

	return 0;
}
