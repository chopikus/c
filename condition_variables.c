#include <stdio.h>
#include <threads.h>
#include <stdbool.h>
#define VALUE_COUNT_MAX 5

int value[VALUE_COUNT_MAX];
int value_count=0;
mtx_t value_mtx;
cnd_t value_cnd;

int run(void *arg)
{	
	while (true)
	{
		mtx_lock(&value_mtx);
		while (value_count<VALUE_COUNT_MAX){
			puts("thread is waiting");
			cnd_wait(&value_cnd, &value_mtx);	
		}		
		puts("thread is awake!!");
		int sum=0;
		for (int i=0; i<VALUE_COUNT_MAX; i++)
			sum+=value[i];
		printf("sum of this 5 is %d\n", sum);
		value_count = 0;
		mtx_unlock(&value_mtx);
	}
	return 0;
}

int main()
{
	thrd_t t;
	thrd_create(&t, run, NULL);
	thrd_detach(t);
	mtx_init(&value_mtx, mtx_plain);
	cnd_init(&value_cnd);
	while (true)
	{
		int n=0;
		scanf("%d", &n);
		mtx_lock(&value_mtx);
		value[value_count++] = n;
		if (value_count==5)
		{
			printf("main: signalling thread\n");
			cnd_signal(&value_cnd);
		}
		mtx_unlock(&value_mtx);
	}
	return 0;
}
