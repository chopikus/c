#include <stdio.h>

struct point{
	int x, y;
};

void print(struct point* p)
{
	printf("%d %d", p->x, p->y);
}

int main()
{
	print(&(struct point) {2, 3});
	return 0;
}
