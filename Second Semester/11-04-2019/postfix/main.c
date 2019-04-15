#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include <string.h>


int main(int argc, char* argv[]){
	char* a = argv[1];
	stackInit();
	for(int i = 0; i<strlen(a); i++){
		if(a[i] == '+'){
			push(pop() + pop());
		}else if(a[i] == '*'){
			push(pop() * pop());
		}else if(a[i] >= '0' && a[i] <= '9'){
			push(0);
		}
		while(a[i] >= '0' && a[i] <= '9'){
			push(10 * pop() + a[i++] - '0');
		}
	}
	printf("%d", pop());
	return 0;
}