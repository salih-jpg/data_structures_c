/*Write a program that checks the given mathematical expression to check if the given parentheses match. 
Your program must accept braces and brackets also.
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#define size 50
char stack[size];
int top = 0;

char pop()
{
	if(top > -1)
	{
		return stack[--top];	
	}
	else{
		printf("\nERROR: underflow");
	}
	
}

void push(char a)
{
	if(top < size-1)
	{
		stack[top++] = a;	
	}else{
		printf("\nERROR: overflow");
	}
		
}

int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}

int phrantesesMatch(char *str){
	for(int i = 0; i<strlen(str); i++){

		if(str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			push(str[i]);
			
		}else if(str[i]==')'|| str[i]=='}' || str[i]==']'){
			
			char popped = pop();
			
		if(match(popped, str[i])){
			return 1;
			}else{
			 return 0;
		}
			 
	}
 }

}


int main(){
    char str[50];
    printf("enter your equation");
    gets(str);
	if(phrantesesMatch(str)){
		printf("your equation is valid");	
	}else{
		printf("your equation is not valid");
	}
        return 0;
 }

