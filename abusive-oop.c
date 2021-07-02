#include <stdio.h>
#include <stdlib.h>

struct parent {
	long long a,b;
};

struct child {
	struct parent super;
	long long a, b;
};

void print(struct parent* p)
{
	printf("%lld\n", p->a);
	printf("%lld\n", p->b);
}

int main()
{
	struct child* ch = malloc(sizeof(struct child));
	struct parent* pr = malloc(sizeof(struct parent));
	pr->a = -1;
	pr->b = 0;
	ch->super = *pr;
	ch->a = 1;
	ch->b = 2;
	print(pr);
	print(ch);
}
