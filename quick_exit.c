#include <stdio.h>
#include <stdlib.h>

void on_quick_exit1(void)
{
	printf("quick exit 1");
	fflush(stdout);
}
void on_quick_exit2(void)
{
	printf("quick exit 2");
	fflush(stdout);
}
void on_quick_exit3(void)
{
	printf("quick exit 3");
	fflush(stdout);
}
	
int main()
{
	printf("hello!");
	at_quick_exit(on_quick_exit2);
	at_quick_exit(on_quick_exit1);
	at_quick_exit(on_quick_exit3);
	/// exit without flushing shit
	quick_exit(0);
}
