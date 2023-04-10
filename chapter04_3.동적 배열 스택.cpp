#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element *data; //data를 저장할거니깐 data에 메모리 할당을 해준다.
	int capacity;
	int top; 
} StackType;

void init_stack(StackType *s){
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
	if(is_full(s))
	{
		s->capacity *= 2;
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element)); 
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top--)];
	}
}

int main(void)
{
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	return 0;
}
