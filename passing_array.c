#include <stdio.h>

int a[3][3][3];

void my_function(int *arr, int n, int m, int k)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			for (int t=0; t<k; t++){
				int* p = arr+i*m*k+j*k+t;
				*p *= 2;
			}
		}
	}
}

int main(void)
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			for (int k=0; k<3; k++)
				a[i][j][k] = i*9+j*3+k+1;	
	my_function(a[0], 3, 3, 3);
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
			for (int k=0; k<3; k++)
				printf("%d %d %d %d\n", i, j, k, a[i][j][k]);
	}
	return 0;
}
