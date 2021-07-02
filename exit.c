#include <stdio.h>
#include <stdlib.h>

void on_exit1(void)
{
	printf("exit 1");
}
void on_exit2(void)
{
	printf("exit 2");
}
void on_exit3(void)
{
	printf("exit 3");
}
	
int main()
{
	atexit(on_exit2);
	atexit(on_exit1);
	atexit(on_exit3);
	return 0;
}
