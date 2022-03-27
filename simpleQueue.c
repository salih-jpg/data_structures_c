#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty(){
	if(rear == -1 ){
		return 1;
	}else{
		return 0;
	}
}

int isFull(){
	if(rear == SIZE -1){
		return 1;
	}else{
		return 0;
	}
}

void enque(int d){
	if(isEmpty()){
		front++;
		rear++;
		queue[rear] = d;
	}else if (isFull()){
		printf("queue is full!! ");
	}else{
		rear++;
		queue[rear] = d;
	}
}

void deque(){
	
	if(isEmpty()){
		printf("queue is empty!! ");
	}else{
		printf("deleted:%d| ", queue[front]);
		for(int i = 0; i < 10; i++){
			queue[i] = queue[i+1];
		}
		rear--;
	}
}

void print(){
	for(int i = 0; i < rear+1; i++){
		printf(" %d->", queue[i]);
	}
}


int main() {
	enque(1);
	enque(2);
	enque(3);
	enque(4);
	enque(5);
	print();
	deque();
	print();
	deque();
	deque();
	print();
	deque();
	deque();
	deque();
	print();

	return 0;
}