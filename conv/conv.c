#include <stdio.h>

int main(int argc, char **argv) {
	unsigned int val;

	printf("%d\n", argc);

	if (argc < 2) {
		return 1;
	}

	sscanf(argv[1], "%u", &val);
	printf("%08x\n", val);

	return 0;
}
