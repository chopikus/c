#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

tss_t str;
/// tss_get => get info (differs on thread)
/// tss_set => set info (differs on thread)
/// tss_create => init variable of type tss_t
/// tss_delete => delete info stored in tss (from ALL threads!)

void my_func(void)
{
	char* tss_str = tss_get(str);
	//when writing tss_get it understands which thread the function was called from.
	printf("TSS string: %s\n", tss_str);
}

int run(void *arg)
{
	int id = *(int*)arg;
	free(arg);
	char *s = malloc(100);
	sprintf(s, "hello from thread %d", id);
	tss_set(str, s);
	my_func();
	return 0;
}

int main()
{
	thrd_t t[5];
	tss_create(&str, free);
	for (int i=0; i<5; i++)
	{
		int* par = malloc(sizeof(int));
		*par = i;
		thrd_create(t+i, run, par);
	}
	for (int i=0; i<5; i++)
		thrd_join(t[i], NULL);
	tss_delete(str);
	return 0;
}
