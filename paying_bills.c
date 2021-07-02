#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	long result=0;
	for (int i=1; i<argc; i++)
	{
		char* s = argv[i];
		char* err;
		long element = strtol(s, &err, 10);
		if (*err=='\0')
			result+=element;
		else
		{
			printf("got a bad character in %d'th number (%c), and it's bad hence we're working on numbers!", i, *err);
			return 1;
		}
	}
	printf("%ld", result);
	getchar();
	return 0;
}
