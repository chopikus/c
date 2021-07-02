#include <stdio.h>
#include <unistd.h>

int main()
{
	for (int i=10; i>=0; i--)
	{
		printf("\rT minus %d second%s... ", i, i!=1?"s":"");
		fflush(stdout);
		sleep(1);
	}	
	return 0;
}
