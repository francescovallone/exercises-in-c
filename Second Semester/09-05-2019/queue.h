#include "itemqueue.h"


struct node{
	Item value;
	struct node* next;
};


typedef struct node Node;
typedef Node* ptrNode;


void queueInit();
void enqueue(Item);
Item dequeue();
int isEmpty();