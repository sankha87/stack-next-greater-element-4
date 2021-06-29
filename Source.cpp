#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack
{
	int top;
	int capacity;
	int items[10] = {};
};

int isFull(struct Stack *st)  // Stack is full when top is equal to the last index 
{
	return (st->top == st->capacity - 1);
}
int isEmpty(struct Stack *st)  // Stack is empty when top is equal to -1 
{
	return (st->top == -1);
}

void push(struct Stack *st, int item)
{
	if (isFull(st))
	{
		printf("\nStack is full \n");
		return;
	}
	st->top++;
	st->items[st->top] = item;
}

int pop(struct Stack *st)
{
	if (isEmpty(st))
		return INT_MIN;
	int temp = st->items[st->top];
	st->top--;
	return temp;
}

void printNGE(int *arr, int n)
{
	struct Stack s;
	int element;
	s.top = -1;
	push(&s, *(arr+0));
	for (int i = 1; i < n; i++)
	{
		element = pop(&s);
		while (element < *(arr+i))
		{
			printf("%d  ->  %d \n", element, *(arr+i));
			if (isEmpty(&s))
				break;
			element = pop(&s);
		}

		if (element > *(arr+i))
			push(&s, element);

		push(&s, *(arr+i));
	}
	while (!isEmpty(&s))
	{
		printf("%d  ->  -1 \n", s.items[s.top]);
		element = pop(&s);
	}
}
void main()
{
	int *arr, n;
	printf("Enter size of the array : ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("\nEnter the elements of the array : ");
	for (int i = 0; i < n; i++)
		scanf("%d", (arr+i));
	printf("\nNext greater elements are : \n");
	printNGE(arr, n);

	_getch();
}