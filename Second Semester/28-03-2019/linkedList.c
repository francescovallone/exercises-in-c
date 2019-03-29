#include <stdio.h>
#include <stdlib.h>

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
	ptrNode head = NULL;
	int choice;
	char c;
	// printf("Write a number [Range: 1-3]: ");
	// scanf("%d", &choice);
	// getchar();
	// while(choice != 4){
	// 	switch (choice){
	// 		case 1:
	// 			printf("Enter a char: ");
	// 			scanf("%c", &c);
	// 			insert(&head, c);
	// 			printList(head);
	// 			break;
	// 		case 2:
	// 			if(!isEmpty(head)){
	// 				printf("Enter a char: ");
	// 				scanf("%c", &c);
	// 				if(delete(&head, c)){
	// 					printf("\nYay, element %c deleted\n", c);
	// 					printList(head);
	// 				}else{
	// 					printf("\nThe element is not in the list, dumbass!");
	// 				}
	// 			}else{
	// 				printf("\nThe list is empty, dumbass!");
	// 			}
	// 			break;
	// 		case 3:
	// 			if(!isEmpty(head)){
	// 				printList(head);
	// 				printf("Enter a char: ");
	// 				scanf("%c", &c);
	// 				if(search(head, c)){
	// 					printf("\nThe char %c is in the list\n", c);
	// 				}else{
	// 					printf("\nThe char %c is not in the list\n", c);
	// 				}
	// 			}
	// 	}
	// 	printf("Write a number [Range: 1-2]: ");
	// 	scanf("%d", &choice);
	// 	getchar();
	// }
	freeList(head);
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