#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <unistd.h>

const int THREAD_COUNT = 5;

int run_my_fing_thread(void *arg)
{
	int value = *((int*) arg);
	free(arg);
	sleep(20);
	printf("Thread %d is actually running!\n", value);
	return value*2;
}

int main()
{
	thrd_t *t = malloc(sizeof(thrd_t)*THREAD_COUNT);
	for (int tr_index=0; tr_index<THREAD_COUNT; tr_index++)
	{
		int* arg = malloc(sizeof(int));
		*arg = tr_index;
		thrd_create(t+tr_index, run_my_fing_thread, arg);
		thrd_detach(*(t+tr_index));
	}
	sleep(10);
	return 0;
}
