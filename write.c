#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* f = fopen("output.bin", "wb");
	char bytes[5] = {0, 12, 3, 2, 12};
	fwrite(bytes, sizeof(char), sizeof(bytes)/sizeof(char), f);
	for (int i=0; i<5; i++)
		printf("%d ", bytes[i]);
	fclose(f);
	return 0;
}
