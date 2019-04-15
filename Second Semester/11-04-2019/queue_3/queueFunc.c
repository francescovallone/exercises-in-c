#include "item.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static Item *s;
static int N, head, tail, maxN = 2;


static void resize(int new_size);
int min(int a, int b);
void merge(int left, int middle, int middle2, int right);


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
		if((N<maxN) && (maxN > 4)){
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


void mergeSort(){
	for(int i = 1; i<N; i*=2){
		for(int j = 0; j<N; j+=i*2){
			merge(j, j+i-1, j+i, min(j+i*2-1, N-1));
		}
	}
}


void merge(int left, int middle, int middle2, int right){
	size_t leftIndex = left;
	size_t rightIndex = middle2;
	size_t combinedIndex = left;
	Item temp[N];
	while (leftIndex <= middle && rightIndex <= right){ 
        if (s[leftIndex] < s[rightIndex]){ 
            temp[combinedIndex++] = s[leftIndex++];
        }else{ 
			temp[combinedIndex++] = s[rightIndex++];
        }
    }
	if(leftIndex == middle2){
		while(rightIndex <= right){
			temp[combinedIndex++] = s[rightIndex++];
		}
	}else{
		while(leftIndex <= middle){
			temp[combinedIndex++] = s[leftIndex++];		
		}
	}
	for(int i=left; i<=right; i++){
		s[i] = temp[i];
	}
}


int min(int a, int b){
	if(a<b){
		return a;
	}
	return b;
}


void printArray(){
	for(int i=0; i<N; i++){
		printf("|%3d", s[i]);
	}
	printf("|\n");
}