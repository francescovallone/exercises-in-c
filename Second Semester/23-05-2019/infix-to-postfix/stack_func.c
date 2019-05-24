#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"



struct stackNode{
	Item item;
	struct stackNode* next;
};

typedef struct stackNode stackNode;
typedef stackNode* stackPtr;


struct stack{
	stackPtr top;
	int N;
};


S stackInit(){
	S stack = malloc(sizeof(S));
	stack->top = NULL;
	stack->N = 0;
	return stack;
}


int stackIsEmpty(S stack){
	return ((stack->top) == NULL);
}


void stackPush(S stack, Item item){
	stackPtr x = malloc(sizeof(*x));
	if(x != NULL){
		x->item = item;
		x->next = stack->top;
		stack->top = x;
		(stack->N)++;
	}else{
		printf("Sei Scarso!");
	}
}


Item stackPop(S stack){
	if(stack->top != NULL){
		stackPtr temp = stack->top;
		Item item = stack->top->item;
		stack->top = stack->top->next;
		free(temp);
		(stack->N)--;
		return item;
	}
	return -1;
}


Item stackPeek(S stack){
	if(stack->top != NULL){
		Item item = stack->top->item;
		return item;
	}
	return -1;
}


int stackSize(S stack){
	return (stack->N);
}


int isOperator(char c){
	return ((c >= 42  && c <= 43) || c == 45 || c == 47);
}

// */+-
int hasPrecedence(char op1, char op2){
	if(op1 == '+'){
		return (op2 == '-' ? 0 : 1);
	}else if(op1 == '/'){
		return (op2 == '*' ? 0 : 1);
	}else if(op1 == '-'){
		return 0;
	}
	return 1;
}