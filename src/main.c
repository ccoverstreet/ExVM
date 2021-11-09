// main
// Cale Overstreet
// Nov. 8, 2021

#include "./stack.h"

int main() {
	FixedStack *stack = FixedStack_create(4);
	FixedStack_print(stack);

	if (
		FixedStack_push(stack, 1)
		|| FixedStack_push(stack, 2)
		|| FixedStack_push(stack, 3)
		|| FixedStack_push(stack, 4)
	   ) return 1;

	printf("\n");
	FixedStack_print(stack);

	uint32_t a, b, c, d;
	if (
		FixedStack_pop(stack, &a)
		|| FixedStack_pop(stack, &b)
		|| FixedStack_pop(stack, &c)
		|| FixedStack_pop(stack, &d)
	   ) return 1;

	printf("\n%u, %u, %u, %u\n", a, b, c, d);

	printf("\n");
	FixedStack_print(stack);

	FixedStack_destroy(stack);

	return 0;
}
