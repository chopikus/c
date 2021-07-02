#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

void print(struct node* top)
{
	while (top!=NULL){		
		printf("%d", top->value);
		if (top->next!=NULL)
			printf("->");
		top = top->next;
	}
}

struct node* reverse_list(struct node* top)
{
	struct node *next = NULL, *prev = NULL;
	while (top!=NULL)
	{
		next = top->next;
		top->next = prev;
		prev = top;
		top = next;
	}	
	return prev;
}

int main()
{
	int x=0;
	struct node* top = NULL;
	struct node* prev = NULL;
	while (scanf("%d", &x)==1)
	{
		struct node* cur = malloc(sizeof(struct node));
		if (top==NULL)
			top = cur;
		if (prev!=NULL)
			prev->next = cur;
		cur->value = x;
		prev = cur;	
	}
	print(top);
	top = reverse_list(top);
	puts("");
	print(top);
	return 0;
}
