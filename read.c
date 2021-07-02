#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* f = fopen("output.bin", "rb");
	char bytes[5] = {0, 1, 2, 3, 4};
	while (fread(bytes, sizeof(char), 1, f)>0)
		printf("%d ", bytes[0]);
	return 0;
}
