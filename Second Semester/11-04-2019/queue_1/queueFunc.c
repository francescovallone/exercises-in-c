#include "item.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static ptrNode head, tail;

void queueInit(){
	head = NULL;
}

int isEmpty(){
	return head == NULL;
}

void enqueue(Item item){
	ptrNode x = malloc(sizeof *x);
	if(x != NULL){
		x->value = item;
		x->next = NULL;
		if(isEmpty()){
			head = tail = x;
		}else{
			tail->next = x;
			tail = tail->next;
		}
	}else{
		printf("Nopeeeee!");
	}
}


Item dequeue(){
	if(head != NULL){
		Item value;
		ptrNode temp;
		value = head->value;
		temp = head;
		head = head->next;
		if (isEmpty) tail = NULL;
		free(temp);
		return value;
	}
	printf("The queue is empty!");
	return NULLITEM;
}