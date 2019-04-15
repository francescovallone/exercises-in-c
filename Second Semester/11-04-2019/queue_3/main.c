#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"


int main(void){
	queueInit();
	Item value;
	unsigned int choice;
	printf("Choose a number between 1 and 3: ");
	scanf("%u", &choice);
	getchar();
	while(choice != 4){
		switch(choice){
			case 1:
				printf("Enter an int: ");
				scanf("%d", &value);
				getchar();
				enqueue(value);
				break;
			case 2:
				if(!isEmpty()){
					printf("The popped element is %d\n", dequeue());
				}else{
					printf("The array is empty!\n");
				}
				break;
			case 3:
				if(!isEmpty()){
					printf("Array non ordinato!\n");
					printArray();
					mergeSort();
					printf("Array ordinato! \n");
					printArray();
				}
			default:
				printf("Invalid choice.\n");
				break;
		}
		printf("Choose a number between 1 and 3: ");
		scanf("%u", &choice);
		getchar();
	}
	return 0;
}