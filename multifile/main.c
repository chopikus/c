#include <stdio.h>
#include "hello.h"
#include "fact.h"

int main(void)
{
	print_hello();
	printf("%d", factorial(6));
	return 0;
}
