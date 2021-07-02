#include <stdio.h>
#include <threads.h>
#include <unistd.h>
#ifdef __STDC_NO_THREADS__
#error fucking shit, compiler does NOT support threads!
#endif

int run_my_thread(void* p)
{
	puts("my thread start");
	int* a = (int*) p;
	for (int i=0; i<20; i++){
		usleep(500000); //sleeping 0.5 seconds
		if (i%2==0)
			printf("\rworking....");
		else
			printf("\r           ");
		fflush(stdout);
	}
	printf("\rmy thread finished!!\n");
	return 232332;
}

int main()
{
	thrd_t t;
	int arg = 123123;
	thrd_create(&t, run_my_thread, &arg);	
	sleep(2);
	printf("\nmain thread worked also\n");
	sleep(2);
	int result = 0; 
	thrd_join(t, &result);
	printf("my thread result: %d", result);
	thrd_join(t, &result);
	printf("\n1");
	thrd_join(t, &result);
	printf("\n2");
	thrd_join(t, &result);
	printf("\n3");
	return 0;
}
