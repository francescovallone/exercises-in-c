#include "item.h"
#include <stdbool.h>


void treeInit(void);
int treeIsEmpty(void);
void treeInsertNode(Item);

void treeInOrder(void);
void treePreOrder(void);
void treePostOrder(void);

bool search(Item);
void print(void);
int treeDistance(Item, Item);
void treeDeleteMin(void);
void treeDelete(Item);