#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t count = 0;

void sigint_handler(int signum)
{
	signal(SIGINT, sigint_handler);
	count++;
}

int main()
{
	signal(SIGINT, sigint_handler);
	while (count<2);
	return 0;
}
