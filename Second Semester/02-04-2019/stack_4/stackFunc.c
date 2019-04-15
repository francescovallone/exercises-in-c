#include <stdio.h>
#include <stdlib.h>
#include "item.h"


#define MAXINT 10;

static Item* a;
static int top = 0;
static int size = 1;


void stackInit(){
	a = malloc((size)*sizeof(Item));
}


void resize(int new_size){
	a = realloc(a, new_size*sizeof(Item));
	size = new_size;
}


int isEmpty(){
	return (size == 0);
}


void push(Item item){
	if(top == size-1){
		resize(size*2);
	}
	a[top++] = item;
}


Item pop(){
	if((top<size/4) && (top > 4)){
		resize(size/2);
		size = size/2;
	}
	top--;
	return a[top];
}