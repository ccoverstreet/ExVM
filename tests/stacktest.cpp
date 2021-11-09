#include "../src/stack.h"
#include <assert.h>
#include <functional>

void testPush() {
	FixedStack stack(4);

	assert(!stack.push(1));
	assert(!stack.push(2));
	assert(!stack.push(3));
	assert(!stack.push(4));

	// Should fail
	assert(stack.push(1));
}

void testPop() {
	FixedStack stack(4);

	assert(!stack.push(1));
	assert(!stack.push(2));
	assert(!stack.push(3));
	assert(!stack.push(4));


	uint32_t a, b, c, d;
	assert(!stack.pop(d));
	assert(!stack.pop(c));
	assert(!stack.pop(b));
	assert(!stack.pop(a));

	assert(d == 4);
	assert(c == 3);
	assert(b == 2);
	assert(a == 1);

	// Should fail
	assert(stack.pop(a));
}

struct Test {
	const char *name;
	std::function<void()> func;
};

int main() {
	Test test_cases[2] {
		{"Push", testPush},
		{"Pop", testPop}
	};

	for (auto test : test_cases) {
		printf("TEST: %s\n", test.name);
		test.func();
		printf("\tPASSED\n");
	}

	return 0;
}
