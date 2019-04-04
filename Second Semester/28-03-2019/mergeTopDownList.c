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
void mergeTopDown(ptrNode *headPtr);
void getMiddle(ptrNode head, ptrNode* left, ptrNode* middle);



int main(void){
	ptrNode head = NULL;
	ptrNode result;
	srand(time(NULL));
	for(int i=0; i<ITEMS; i++){
		insert(&head, (97 + (rand() % ITEMS)));
	}
	printList(head);
	mergeTopDown(&head);
	printList(head);
	freeList(head);
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
		while(currentPtr != NULL){
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


void mergeTopDown(ptrNode* headPtr){
	ptrNode head = (*headPtr);
	ptrNode left, middle;
	if(head == NULL || head->next == NULL){
		return;
	}
	getMiddle(head, &left, &middle);
	mergeTopDown(&left);
	mergeTopDown(&middle);
	(*headPtr) = merge(left, middle);
}


void getMiddle(ptrNode head, ptrNode* left, ptrNode* middle){
	ptrNode fast, slow;
	slow = head;
	fast = head->next;
	while(fast != NULL){
		fast = fast->next;
		if(fast != NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	*left = head;
	*middle = slow->next;
	slow->next = NULL;
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