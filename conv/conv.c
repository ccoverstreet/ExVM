#include <stdio.h>

int main(int argc, char **argv) {
	unsigned short val;

	printf("%d\n", argc);

	if (argc < 2) {
		return 1;
	}

	sscanf(argv[1], "%hd", &val);
	printf("%x\n", val);

	return 0;
}
