#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*                            ascýý name codes
	BERSAN MUHAMMET EKICI = 
	BEYZA AYDIN 
	EGEMEN KARAMAN
	ISMAIL ESAT ERBAY
	KEREM KORKUT TURAN
	OKAN KUKUL
	RUVEYDA ARDIC
	SALIH YELEN
	SAMET ERÞEN
	SEHER OVA
	YASIN GORGUN
	SEYMA NUR CIN
*/
#define SIZE 20

struct DataItem{
	int name;
	int key;	
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* trsh;
struct DataItem* item;

int hashCode(int key) {
   return key % SIZE;
}

struct DataItem* search(int key){
	int hashIndex = hashCode(key);
	
	while(hashArray[hashIndex] != NULL){
		
		if(hashArray[hashIndex]->key == key){
			return hashArray[hashIndex];
		}
		
		hashIndex++;
		
		hashIndex %= SIZE;	
	}
	
	return NULL;
}

void insert(int key,char name[]){
	
	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	item->name = name;
	item->key = key;
	
	int hashIndex = hashCode(key);
	
	while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {

      ++hashIndex;
      hashIndex %= SIZE;
   }
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   int key = item->key;

   int hashIndex = hashCode(key);

   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         hashArray[hashIndex] = trsh; 
         return temp;
      }
		
      ++hashIndex;
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->name);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

int main() {
   trsh = (struct DataItem*) malloc(sizeof(struct DataItem));
   trsh->name = -1;  
   trsh->key = -1; 

   insert(20003301, 23);//BERSAN MUHAMMET EKÝCÝ
   insert(20003302, 70);
   insert(20003303, 80);
   insert(20003304, 25);
   insert(20003305, 44);
   insert(20003306, 32);
   insert(20003307, 11);
   insert(20003308, 10);
   insert(20003309, 12);
   insert(20003310, 23);
   insert(20003311, 43);
   insert(20003312, 56);
   display();
   item = search(20003301);

   if(item != NULL) {
      printf("student found: %d\n", item->name);
   } else {
      printf("student not found\n");
   }

   delete(item);
   item = search(20003301);

   if(item != NULL) {
      printf("student found: %d\n", item->name);
   } else {
      printf("student not found\n");
   }
}