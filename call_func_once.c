#include <stdio.h>
#include <threads.h>
#include <stdbool.h>

const bool SHOULD_CALL_ONCE = false;
//true => func will be called once, otherwise called THREAD_MAX_COUNT times
const int THREAD_MAX_COUNT = 5;
once_flag flag = ONCE_FLAG_INIT;

void my_func(void)
{
	printf("HELLO\n");
}

int run(void* shit)
{
	if (SHOULD_CALL_ONCE)
		call_once(&flag, my_func);
	else
		my_func();
	return 0;
}

int main()
{
	thrd_t ts[THREAD_MAX_COUNT];
	for (int i=0; i<5; i++)
		thrd_create(ts+i, run, NULL);
	for (int i=0; i<5; i++)
		thrd_join(ts[i], NULL);
	return 0;
}
