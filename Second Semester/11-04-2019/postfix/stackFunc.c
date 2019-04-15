#include <stdio.h>
#include <stdlib.h>
#include "item.h"


static Item* a;
static int N = 0;
static int maxN = 2;

static void resize(int new_size);


void stackInit(){
	a = malloc((maxN)*sizeof(Item));
}


static void resize(int new_size){
	a = realloc(a, new_size*sizeof(Item));
	maxN = new_size;
}


int isEmpty(){
	return (maxN == 0);
}


void push(Item item){
	if(N >= maxN){
		resize(maxN*2);
	}
	a[N] = item;
	N++;
}


int pop(){
	if((N<maxN/4) && (N > 4)){
		resize(maxN/2);
	}
	N--;
	return a[N];
}