#include <stdio.h>
#include <stdlib.h>

#define SIZE 2

int main(void) {
	//example arrays
	int Arr1[SIZE][SIZE] = {{1,1}, {1,1}},
	    Arr2[SIZE][SIZE] = {{2,2}, {2,2}},
		totalArr[SIZE][SIZE];			  
	
	int i,j,k;
	
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
		  totalArr[i][j] = 0;
		  for(k = 0; k < SIZE; k++){
		  	totalArr[i][j] += Arr1[i][k]*Arr2[k][j]; 
		  }
		}	
	}		
	
	for(i=0;i<SIZE;i++)    
	{    
		for(j=0;j<SIZE;j++)    
			{    
				printf("%d ",totalArr[i][j]);    
			}    
		printf("\n");    
	}    	
		  
	return 0;
}
