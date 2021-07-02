#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* val = getenv("JAVA_HOME");
	if (val==NULL)
		puts("no java home");
	else
		puts(val);
	return 0;
}
