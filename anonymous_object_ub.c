#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool condition = true;

int* get_int()
{
	return &(int){0};
}

void print(int *p)
{
	if (condition){
		int y = (int) {1};
		&y;
	}
	printf("%d", *p);
}

int main()
{
	print(get_int());	 ///based on condition it will print out 0 or 1
	return 0;
}
