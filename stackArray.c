#include <stdio.h>
#include <stdlib.h>

#define size 3
int stack[size];
int top = 0;

int pop()
{
	if(top > -1)
	{
		return stack[--top];	
	}
	else{
		printf("\nERROR: underflow");
	}
	
}

void push(int a)
{
	if(top < size-1)
	{
		stack[top++] = a;	
	}else{
		printf("\nERROR: overflow");
	}
		
}

int print(){
	for(int i = 0; i<top; i++){
		printf("%d ", stack[i]);
	}
}

int main(void)
{
	push(4);
	push(2);
	push(5);
	print();
	printf("popped %d ", pop());
	printf("popped %d ", pop());
	printf("popped %d ", pop());
		
	
}