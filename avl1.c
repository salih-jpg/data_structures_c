#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	int height;
};

int max(int a, int b);

int height(struct Node* N){
	if(N == NULL)
		return 0;
	return N->height; 
}

int max(int a, int b){
	return (a > b) ? a : b;
}

struct Node* newNode(int key){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	  node->key = key;
	  node->left = NULL;
	  node->right = NULL;
	  node->height = 1;
	  return (node);
}

struct Node* rightRotate(struct Node* y){
	struct Node* x = y->left;
	struct Node* T = x->right;
	
	x->right = y;
	y->left = T;
	
	y->height = max(height(y->left), height(y->right)) +1;
	x->height = max(height(x->left), height(x->right)) +1;
	
	return x;
}

struct Node* leftRotate(struct Node* x){
	struct Node* y = x->right;
	struct Node* T = y->left;
	
	y->left = x;
	x->right = T;
	
	x->height = max(height(x->left), height(x->right)) +1;
	y->height = max(height(y->left), height(y->right)) +1;
	
	return y;
}

int getBalance(struct Node* n){
	if(n == NULL)
		return 0;
	return height(n->left) - height(n->right);
}

struct Node* insert(struct Node* node, int key)
{
	if(node == NULL)
		return newNode(key);

	if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = getBalance(node);

	if(balance > 1 && key < node->left->key)
		return rightRotate(node);
	if(balance < -1 && key > node->right->key)
		return leftRotate(node);
	if(balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

struct Node* minValue(struct Node* node)
{
	struct Node* current = node;
	while(current != NULL)
		current = current->left;
	return current;  
}

struct Node* deleteNode(struct Node* root, int key)
{
	if(root == NULL)
		return root;

	if(key < root->key)
		root->left = deleteNode(root->left, key);
	if(key > root->key)
		root->right = deleteNode(root->right, key);

	else{
		if(root->right = NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}

		if(root->left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;
		}

		struct Node* temp = minValue(root->right);

		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);

	}

	if(root = NULL)
		return root;

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance = getBalance(root);

	if(balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if(balance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(balance < -1 && getBalance(root->right) >= 0)
		return leftRotate(root);

	if(balance < -1 && getBalance(root->right) < 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;

}

void printPre(struct Node* node){

	if(node != NULL){
		printPre(node->left);
		printf("%d->", node->key);
		printPre(node->right);
	}
}


int main() {
	 
  struct Node *root = NULL;

  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 7);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 8);

  printPre(root);

  root = deleteNode(root, 3);

  printf("\nAfter deletion: ");
  printPre(root);

  return 0;
}