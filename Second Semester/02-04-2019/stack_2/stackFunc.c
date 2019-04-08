#include <stdio.h>
#include <stdlib.h>
#include "item.h"


static Item stackArray[10];
static int size = 0;


int isEmpty(){
	return (size == 0);
}


void push(Item item){
	if(size <= 10){
		stackArray[size] = item;
		size++;
	}else{
		printf("You exceed array length");
	}
}


int pop(){
	size--;
	return stackArray[size];
}