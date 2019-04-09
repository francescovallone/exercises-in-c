#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"


int main(void){
	Item* a = malloc(0*sizeof(Item));
	a = resize(a);

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
				push(a, value);
				break;
			case 2:
				if(!isEmpty()){
					printf("The popped element is %d", pop(a));
				}else{
					printf("The array is empty!");
				}
				break;
			default:
				printf("Invalid choice");
				break;
		}
		printf("\nChoose a number between 1 and 2: ");
		scanf("%u", &choice);
		getchar();
	}
	free(a);
	return 0;
}