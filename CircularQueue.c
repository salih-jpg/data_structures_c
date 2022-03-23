#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty(){
	if(front == -1){
		return 1;
	}
	return 0;
}

int isFull(){
	if((front == rear+1) || (front == 0 && rear == SIZE-1)){
		return 1;
	}else{
		return 0;	
	}
	
}

int deque(){
	int element;
	if(isEmpty()){
		printf("Queue is empty");
		return -1;
	}else{
		element = queue[front];
		if(front == rear){
			front = -1;
			rear = -1;
		}else{
			front = (front +1)%SIZE;
		}
		return element;
	}
	
}
void enque(int a){
	if(isFull()){
		printf("Queue is full");
	}else{
		if(front == -1) {
			front = 0;			
		}
		rear = (rear +1)%SIZE;
		queue[rear] = a;		
	}
}

void print(){
	int i;
	for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", queue[i]);
    }
    printf("%d", queue[i]);
}

int main() {
	enque(1);
	enque(2);
	enque(3);
	print();
	printf("\n%d\n", deque());
	printf("\n%d\n", deque());
	print();
	return 0;
}