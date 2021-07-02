#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "");	
	size_t wc_len = mbstowcs(NULL, "§¶°±π€•", 0);
	printf("The size of wide-character string in characters: %zu\n", wc_len);
	return 0;
}
