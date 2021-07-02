#include <stdio.h>
#include <threads.h>

mtx_t mutex;

int run_thread(void* arg)
{
	static int shit = 0;	
	mtx_lock(&mutex);
	printf("shit: %d\n", shit);
	shit++;
	mtx_unlock(&mutex);
	return 0;
}

int THREAD_COUNT = 50;

int main()
{
	mtx_init(&mutex, mtx_plain);
	thrd_t t[THREAD_COUNT];
	for (int i=0; i<THREAD_COUNT; i++)
	{
		thrd_create(t+i, run_thread, NULL);
	}
	for (int i=0; i<THREAD_COUNT; i++)
		thrd_detach(*(t+i));
	sleep(5);
	mtx_destroy(&mutex);
	return 0;
}
