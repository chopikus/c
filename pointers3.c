#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int q1(int x)
{
	return x;
}

int q2(int x)
{
	return 2*x;	
}

int q3(int x)
{
	return 3*x;
}

int cmp(const void* v1, const void* v2)
{
	int (**p1) (int) = v1;
	int (**p2) (int) = v2;
	int (*pp1) (int) = *p1;
	int (*pp2) (int) = *p2; 
	int val1 = pp1(123);
	int val2 = pp2(123);
	if (val1<val2)
		return -1;
	else if (val1==val2)
		return 0;
	else
		return 1;
}

int main()
{
	int (*arr[3]) (int);
	arr[0] = q3;
	arr[1] = q1;
	arr[2] = q2;
	qsort(arr, 3, sizeof(arr[0]), cmp);
	for (int i=0; i<3; i++)
	{
		printf("%d\n", arr[i](123));
	}
	return 0;
}
