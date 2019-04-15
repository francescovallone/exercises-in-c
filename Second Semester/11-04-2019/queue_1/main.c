#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"


int main(void){
	queueInit();
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
				enqueue(value);
				break;
			case 2:
				if(!isEmpty()){
					printf("The popped element is %d", dequeue());
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