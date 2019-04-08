#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"


static ptrStackNode head;


void stackInit(){
	head == NULL;
}


void push(Item item){
	ptrStackNode newPtr = malloc(sizeof *newPtr);
	if(newPtr != NULL){
		newPtr->value = item;
		newPtr->next = head;
		head = newPtr;
	}else{
		printf("Value: %d can't be pushed in the memory.", item);
	}
}


Item pop(void){
	ptrStackNode temp = head;
	Item tempValue = head->value;
	head = head->next;
	free(temp);
	return tempValue;
}


int isEmpty(void){
	return head == NULL;
}