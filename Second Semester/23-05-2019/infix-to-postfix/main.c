#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"


int main(int argc, char* argv){
	char* a = argv[1];
	int N = strlen(a);
	char postFix[N];
	char op;
	postFix[0] = '\0';
	S stack = stackInit();
	S stackN = stackInit();
	stackPush(stack, (Item)('('));
	strcat(a, ")");
	int i = 0, j = 0;
	while(!stackIsEmpty(stack)){
		if(a[i] >= '0' && a[i] <= '9'){
			postFix[j] = a[i];
			postFix[j+1] = '\0';
			j++;
		}
		if(a[i] == '('){
			stackPush(stack, (Item)('('));
		}
		if(isOperator(a[i])){
			while(hasPrecedence(stackPeek(stack).c, a[i])){
				postFix[j] = " ";
				postFix[j+1] = stackPop(stack).c;
				postFix[j+2] = '\0';
				j+=2;
			}
			postFix[j] = ' ';
			postFix[j+1] = '\0';
			j++;
			stackPush(stack, (Item)(a[i]));
		}
		if(a[i] == ')'){
			
		}
	}
	return 0;
}