#include <stdio.h>
#include <stdlib.h>


struct node{
	int x;
	struct	node *next;
};


 struct node* alloc(){
 	return (struct node*)malloc(sizeof(struct node));
 }
 
int pop(struct node* root){
	if(root == NULL){
		printf("underflow");
		return -1;
	}
	if(root->next == NULL){
		int rValue = root->x;
		free(root);
		return rValue;
	}
	struct node* iter = root;
	while(iter->next->next != NULL)
		iter = iter->next;
	struct node* temp = iter->next;
	int rValue = temp->x;
	iter->next = NULL;
	free(temp);
	return rValue;
}
 
struct node* push(struct node *root, int data){
	if(root == NULL){
		struct node* root = alloc();
		root->x = data;
		root->next = NULL;	
		return root;
	}
	struct node* iter = root;
	while(iter->next != NULL)
		iter = iter->next;
	struct node* temp = alloc();
	temp-> x = data;
	temp->next = NULL;
	iter->next = temp;
	return root; 	
			
}

void print(struct node* root){
	while(root != NULL){
		printf("%d ->", root->x);
		root = root->next;
	}
}

int main() {
	struct node* stack = NULL;
	stack = push(stack, 10);
	stack = push(stack, 20);
	stack = push(stack, 30);
	stack = push(stack, 40);
	print(stack);
	printf(" %d ", pop(stack));
	printf(" %d ", pop(stack));
	return 0;	
}