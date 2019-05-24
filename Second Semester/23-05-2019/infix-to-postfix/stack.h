#include "item.h"


typedef struct stack *S;

S stackInit();
int stackIsEmpty(S);
void stackPush(S, Item);
Item stackPop(S);
Item stackPeek(S);
int stackSize(S);
int isOperator(char);
int hasPrecedence(char, char);