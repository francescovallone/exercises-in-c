#include <stdio.h>
#include <stdlib.h>
#include "item.h"


struct node{
	Item value;
	struct node* next;
};
typedef struct node stackNode;
typedef stackNode* ptrStackNode;


// Prototypes
void stackInit();
void push(Item);
Item pop(void);
int isEmpty(void);
