#include "./stack.h"

#include <cstdio>
#include <assert.h>
#include <functional>

void testPushPopCycle() {
	StaticStack<4> stack;

	stack.push(0);
	stack.push(1);
	stack.push(2);
	stack.push(3);

	uint32_t val;
	for (int i = 3; i >= 0; i--) {
		assert(!stack.pop(val));
		assert(val == i);
	}

	assert(!stack.push(0));
	assert(!stack.push(1));
	assert(!stack.push(2));
	assert(!stack.push(3));

	for (int i = 3; i >= 0; i--) {
		assert(!stack.pop(val));
		assert(val == i);
	}
}

void testPushLimit() {
	StaticStack<4> stack;

	assert(!stack.push(0xff));
	assert(!stack.push(0xff));
	assert(!stack.push(0xff));
	assert(!stack.push(0xff));

	// This one should fail
	assert(stack.push(0xff));
}

void testPopLimit() {
	StaticStack<4> stack;

	assert(!stack.push(0xff));
	assert(!stack.push(0xff));
	assert(!stack.push(0xff));
	assert(!stack.push(0xff));

	uint32_t x = 0;
	assert(!stack.pop(x));
	assert(!stack.pop(x));
	assert(!stack.pop(x));
	assert(!stack.pop(x));

	// This one should fail
	assert(stack.pop(x));
}

struct Test {
	const char *name;
	std::function<void()> func;
};

int main() {
	Test test_suite[] {
		{"Pop Push Cycle", testPushPopCycle},
		{"Push Limit", testPushLimit},
		{"Pop Limit", testPopLimit}
	};

	for (auto test : test_suite) {
		printf("\nTEST: %s\n", test.name);
		test.func();
		printf("\tPASSED\n", test.name);
	}

	return 0;
}
