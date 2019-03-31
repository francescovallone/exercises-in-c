#include <stdio.h>
#include <stdlib.h>


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
char delete(ptrNode *ptr, char value);
int isEmpty(ptrNode ptr);
void printList(ptrNode ptr);
void freeList(ptrNode ptr);
ptrNode search(ptrNode ptr, char value);
ptrNode merge(ptrNode list1, ptrNode list2);



int main(void){
	ptrNode head1 = NULL;
	ptrNode head2 = NULL;
	ptrNode result;
	for(int i=0; i<ITEMS; i+=2){
		insert(&head1, 97+i);
		insert(&head2, 98+i);
	}
	printList(head1);
	printList(head2);
	result = merge(head1, head2);
	printList(result);
	freeList(head2);
	freeList(head1);
	freeList(result);
	return 0;
}


void insert(ptrNode *ptr, char value){
	ptrNode newPtr;
	ptrNode previousPtr;
	ptrNode currentPtr;
	newPtr = malloc(sizeof(Node));
	if(newPtr != NULL){
		newPtr->value = value;
		newPtr->next = NULL;
		previousPtr = NULL;
		currentPtr = (*ptr);
		while(currentPtr != NULL && value > currentPtr->value){
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}
		if(previousPtr == NULL){
			newPtr->next = (*ptr);
			(*ptr) = newPtr;
		}else{
			previousPtr->next = newPtr;
			newPtr->next = currentPtr;
		}
	}else{
		printf("Buy more memory!");
	}
}


char delete(ptrNode *ptr, char value){
	ptrNode tempNode;
	ptrNode currentNode;
	ptrNode previousNode;
	if(value == (*ptr)->value){
		tempNode = *ptr;
		*ptr = (*ptr)->next;
		free(tempNode);
		return value;
	}else{
		previousNode = (*ptr);
		currentNode = (*ptr)->next;
		while(currentNode != NULL && currentNode->value != value){
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		if(currentNode != NULL){
			tempNode = currentNode;
			previousNode->next = currentNode->next;
			free(tempNode);
			return value;
		} 
	}
	return '\0';
}


ptrNode search(ptrNode ptr, char value){
	if(ptr == NULL || ptr->value > value) return NULL;
	if(ptr->value == value) return ptr;
	return search(ptr->next, value);
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