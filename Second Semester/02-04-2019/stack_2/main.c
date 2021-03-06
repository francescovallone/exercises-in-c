#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"


int main(void){
	Item value;
	unsigned int choice;
	printf("Choose a number between 1 and 2: ");
	scanf("%u", &choice);
	getchar();
	while(choice != 3){
		switch(choice){
			case 1:
				printf("Enter an int: ");
				scanf("%d", &value);
				getchar();
				push(value);
				break;
			case 2:
				if(!isEmpty()){
					printf("The popped element is %d", pop());
				}else{
					printf("The array is empty!");
				}
				break;
			default:
				printf("Invalid choice");
				break;
		}
		printf("Choose a number between 1 and 2: ");
		scanf("%u", &choice);
		getchar();
	}
	return 0;
}