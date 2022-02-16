#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* resize_array(int* a, int size);

int main(void) {
	int n;
	printf("enter size of array ");
	scanf("%d", &n);
	int *a;
	a = (int*)malloc(sizeof(int) * n);
	
	int i;
	for(i = 0; i < n; i++){
		printf("%d\n", a + i);
	}//showing adresses of array that created new
	
	char yes[1] = "y";
	char check[1];
	printf("do you want to change array size? y,n ");
	fflush(stdin);
	gets(check);
	
	if(strcmp(check,yes))
	{
	printf("enter new size ");
	scanf("%d", &n);
	
	resize_array(a, n);
		
	for(i = 0; i < n; i++){
			printf("%d\n", a + i);
	  }		
	}
		
	return 0;
}

int* resize_array(int* a, int size)
{
	int* new_a = realloc(a, size);

	return new_a;
}
 
