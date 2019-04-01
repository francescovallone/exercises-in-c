#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ITEMS 10


// Instanzio la struct dei nodi.
struct node{
	char value;
	struct node* next;
};
typedef struct node Node;
typedef Node* ptrNode;


// Prototipi
void insert(ptrNode *ptr, char value);
int isEmpty(ptrNode ptr);
void printList(ptrNode ptr);
void freeList(ptrNode ptr);
ptrNode merge(ptrNode list1, ptrNode list2);
ptrNode naturalMerge(ptrNode head);



int main(void){
	ptrNode head = NULL;
	ptrNode result;
	srand(time(NULL));
	for(int i=0; i<ITEMS; i++){
		insert(&head, (97 + (rand() % ITEMS)));
	}
	printList(head);
	result = naturalMerge(head);
	printList(result);
	freeList(head);
	freeList(result);
	return 0;
}


void insert(ptrNode *ptr, char value){
	ptrNode newPtr = malloc(sizeof(Node));
	newPtr->value = value;
	newPtr->next = (*ptr);
	(*ptr) = newPtr;
}


ptrNode merge(ptrNode const list1, ptrNode const list2){
	ptrNode cl1, cl2, result, rc;
	cl1 = list1;
	cl2 = list2;
	if((rc = malloc(sizeof(ptrNode))) == NULL){
		return NULL;
	}
	rc->next = NULL;
	result = rc;
	while((cl1 != NULL) && (cl2 != NULL)){
		if((cl1->value) <= (cl2->value)){
			rc->value = cl1->value;
			cl1 = cl1->next;
		}else{
			rc->value = cl2->value;
			cl2 = cl2->next;
		}
		if((rc->next = malloc(sizeof(ptrNode))) == NULL){
			freeList(result);
			return NULL;
		}
		rc = rc->next;
		rc->next = NULL;
	}
	if(cl1 == NULL){
		rc->value = cl2->value;
		while((cl2 = cl2->next) != NULL){
			if((rc->next = malloc(sizeof(ptrNode))) == NULL){
				freeList(result);
				return NULL;
			}
			rc = rc->next;
			rc->value = cl2->value;
			rc->next = NULL;
		}
	}else{
		rc->value = cl1->value;
		while((cl1 = cl1->next) != NULL){
			if((rc->next = malloc(sizeof(ptrNode))) == NULL){
				freeList(result);
				return NULL;
			}
			rc = rc->next;
			rc->value = cl1->value;
			rc->next = NULL;
		}
	}
	return result;
}


ptrNode naturalMerge(ptrNode head){
	if(head == NULL){
		return NULL;
	}
	ptrNode result, array[ITEMS], natural[ITEMS], next;
	result = head;
	int k=0;
	for(int i=0; i<ITEMS && result != NULL; i++){
		array[i] = result;
		result = result->next;
	}
	for(int i=0; i<ITEMS; i++){
		for(int j=i+1; j<ITEMS; j++){
			if(array[j-1]->value > array[j]->value){
				array[j-1]->next = NULL;
				natural[k] = array[i];
				i = j;
				k++;
			}
		}
	}
	if(array[ITEMS-2] > array[ITEMS-1]){
		natural[k++] = array[ITEMS-1];
	}
	result = NULL;
	for(int i=0; i<k; i++){
		result = merge(natural[i], result);
	}
	return result;
}

int isEmpty(ptrNode ptr){
	if(ptr == NULL) return 1;
	return 0;
}


void printList(ptrNode ptr){
	while(ptr != NULL){
		printf("%c ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}


void freeList(ptrNode ptr){
	while(ptr != NULL){
		ptrNode currentPtr = ptr;
		ptr = ptr->next;
		free(currentPtr);
	}
}