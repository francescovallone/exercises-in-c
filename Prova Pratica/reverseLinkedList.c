#include <stdio.h>
#include <stdlib.h>


struct node{
	int value;
	struct node* next;
};

typedef struct node Node;
typedef Node* ptrNode;


void insert(ptrNode* head, int value){
	ptrNode new = malloc(sizeof(Node));
	new->value = value;
	new->next = (*head);
	(*head) = new;
}


void printList(ptrNode head){
	while(head != NULL){
		printf("%3d", head->value);
		head = head->next;
	}
	printf("\n");
}


ptrNode reverse(ptrNode head){
	ptrNode current = head;
	ptrNode prev = NULL, next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}


int main(){
	ptrNode head = NULL;
	for(int i = 0; i<10; i++){
		insert(&head, i);
	}
	printList(head);
	head = reverse(head);
	printList(head);
	return 0;
}