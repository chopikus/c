#include <stdio.h>
#include <signal.h>
int main()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	while (1);
	return 0;
}
