#include <stdio.h>

int main()
{
	{
		int count = 1;
		label:
			printf("%d\n", count);
			count++;
	};
	goto label;
	return 0;
}
