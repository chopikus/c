#include <stdio.h>
#include <stdarg.h>

int my_printf(int count, const char* format, ...)
{
	va_list va, va1;
	va_start(va,format);
	va_copy(va1, va);
	printf("count: %d\n", count);
	for (int i=0; i<count; i++)
	{
		printf("argument #%d is %d \n", i+1,va_arg(va1, int));
	}
	int return_value = vprintf(format, va);
	va_end(va1);
	va_end(va);
	return return_value;
}

int main()
{
	my_printf(3, "%d %d\n", 1, 2, 3123);
	return 0;
}
