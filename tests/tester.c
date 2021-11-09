#include "../src/stack.h"
#include "../src/vm.h"

#include <assert.h>

void testFixedStackFullTest() {
	FixedStack *stack = FixedStack_create(4);

	assert(!FixedStack_push(stack, 1));
	assert(!FixedStack_push(stack, 2));
	assert(!FixedStack_push(stack, 3));
	assert(!FixedStack_push(stack, 4));

	// This should fail
	assert(FixedStack_push(stack, 1));

	uint32_t a, b, c, d;
	assert(!FixedStack_pop(stack, &a));
	assert(!FixedStack_pop(stack, &b));
	assert(!FixedStack_pop(stack, &c));
	assert(!FixedStack_pop(stack, &d));

	assert(a == 4);
	assert(b == 3);
	assert(c == 2);
	assert(d == 1);

	// This should fail
	assert(FixedStack_pop(stack, &a));

	FixedStack_destroy(stack);
}

void testVMBasic() {
	ExVM *vm = ExVM_create(4, 4);

	assert(!ExVM_push(vm, 1));
	assert(!ExVM_push(vm, 2));
	assert(!ExVM_push(vm, 3));
	assert(!ExVM_push(vm, 4));

	// Should fail
	assert(ExVM_push(vm, 4));

	uint32_t a, b, c, d;

	assert(!ExVM_pop(vm, &a));
	assert(!ExVM_pop(vm, &b));
	assert(!ExVM_pop(vm, &c));
	assert(!ExVM_pop(vm, &d));

	assert(a == 4);
	assert(b == 3);
	assert(c == 2);
	assert(d == 1);

	assert(ExVM_pop(vm, &d));

	ExVM_destroy(vm);
}

typedef struct {
	const char *name;
	void (*func)();
} TestCase;

int main() {
#define N_TESTS 2
	TestCase tests[N_TESTS] = {
		{"FixedStack", testFixedStackFullTest},
		{"VM Basic", testVMBasic}
	};

	for (size_t i = 0; i < N_TESTS; i++) {
		printf("TEST: %s\n", tests[i].name);
		tests[i].func();
		printf("\tPASSED\n");
	}
}
