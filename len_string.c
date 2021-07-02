#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int length;
	char data[];
} len_string;

int main()
{
	char s[1024];
	scanf("%s", s);
	int len = strlen(s);
	len_string* l = malloc(sizeof(len_string)+len);
	l->length = len;
	memcpy(l->data, s, len);
	printf("%s", l->data);
	return 0;
}
