#include <stdio.h>

int main()
{
	int x = 10;
	goto label;

	{
		label: //but adding ; will solve the problem
			int v[x];
			puts("Hi!");	
	};
	return 0;
}
