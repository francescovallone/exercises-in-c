#include "item.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


static Item *s;
static int N, head, tail, maxN = 2;


static void resize(int new_size);


void queueInit(){
	s = malloc(sizeof *s);
	N = head = tail = 0;
}

int isEmpty(){
	return N == 0;
}

void enqueue(Item item){
	if(N >= maxN){
		resize(2*maxN);
		maxN *= 2;
	}
	s[tail] = item;
	tail = (tail+1)%maxN;
	N++;
}


Item dequeue(){
	if(!isEmpty()){
		if((N<maxN/4) && (maxN > 4)){
			resize(maxN/2);
			maxN = maxN/2;
		}
		Item value = s[head];
		head = (head+1)%maxN;
		N--;
		return value;
	}
	printf("The queue is empty!");
	return NULLITEM;
}


void resize(int new_size){
	Item *t = malloc(new_size*sizeof(Item));
	for(int i = head, j = 0; (j <= N) && (j<new_size); i = (i+1)%maxN, j++){
		t[j] = s[i];
	}
	free(s);
	s = t;
	head = 0;
	tail = N;
}