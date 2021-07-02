#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct foo {
	int a;
	char b;
	int c;
	char d;
} foo;

int main()
{
	foo* x = malloc(sizeof(foo));
	printf("%zu\n", sizeof(x->a)+sizeof(x->b)+sizeof(x->c)+sizeof(x->d));
	printf("%zu\n", sizeof(foo));
	printf("%zu\n", offsetof(struct foo, a));
	printf("%zu\n", offsetof(struct foo, b));
	printf("%zu\n", offsetof(struct foo, c));
	printf("%zu", offsetof(struct foo, d));
	return 0;
}
