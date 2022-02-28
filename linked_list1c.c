#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct n *next;
};

struct node* head = NULL;

 struct node* alloc(){
 	return (struct node*)malloc(sizeof(struct node));
 	
 }
 
void insert(int data){
		struct node* root = alloc();
		root->data = data;
		root->next = head;
		head = root;
}

void print(){
	struct node *n = head;
	while(n){
		printf("%d ->", n->data);
		n = n->next;
	}
}

void find(int a){
	int i;
	struct node* iter = head;
	for(i=1; i<a; i++){
		iter = iter->next;
	}
	printf("\n%d has found", iter->data);
}

void del(int a){
	int i;
	struct node* iter = head;
	struct node* temp;
	for(i=0; i<a; i++){
		iter = iter->next;
	}
	temp = iter->next;
	iter->next = iter-> next -> next;
	free(temp);
}



int main(void) {
	
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	// 4->3->2->1
	
	print();
	find(2);
	del(2);
	print();
		
	return 0;
}
