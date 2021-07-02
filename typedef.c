#include <stdio.h>
#include <stdlib.h>

char* read_line(FILE* f)
{
	if (f==NULL)
		return NULL;
	int c=0;
	int line_size=0;
	int buf_size=4;
	char* buf = malloc(sizeof(char)*buf_size);
	if (buf==NULL)
		return NULL;	
	while ((c = getc(f))!=EOF && c!='\n')
	{
		if ((++line_size)>=buf_size)	
		{
			//try reallocating
			buf_size*=2;
			buf = realloc(buf, sizeof(char)*buf_size);
			if (buf==NULL)
				return NULL;
		}	
		//just do the job
		buf[line_size-1] = c;
		buf[line_size] = '\0';
	}
	//try reallocating again for saving memory
	char* new_buf = realloc(buf, sizeof(char)*(line_size+1));
	if (new_buf==NULL)
		return buf;
	return new_buf;
}

int main(void)
{
	char* s = read_line(stdin);
	printf("%s", s);
	return 0;
}
