#include <stdio.h>

typedef enum {
	SHEEP=2,
	WHEAT,
	WOOD=2,
	BRICK,
	ORE
} RESOURCE;

int main()
{
	RESOURCE s=SHEEP, w=WOOD, wh=WHEAT, br =BRICK;
	if (s==w)
	{
		puts("s==w");
	}
	if (wh==br)
		puts("wh==br");
	return 0;
}
