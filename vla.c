#include <stdio.h>

void print_records(int rec_count, int records[rec_count][5])
{
	for (int i=0; i<rec_count; i++)
	{
		for (int j=0; j<5; j++)
		{
			printf("%d ", records[i][j]);
		}
		puts("");
	}
}

int main()
{
	int rec_count = 3;
	int records[rec_count][5];
	for (int i=0; i<rec_count; i++)
	{
		for (int j=0; j<5; j++)
		{
			records[i][j] = (i+1)*(j+1);	
		}
	}	
	print_records(rec_count, records);
	return 0;
}
