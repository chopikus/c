#include <stdio.h>

#define FORMAT(x) _Generic((x), \
														int: "%d", \
														long: "%ld", \
														float: "%f", \
														double: "%f", \
														char*: "%s", \
														long long: "%lld")
#define print(x) { \
	printf(FORMAT(x), x); \
}

int main()
{
	print(124543);
	return 0;
}
