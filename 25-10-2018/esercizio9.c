#include <stdio.h>

int main(){
	int a;
	while(a%2){
		printf("Immetti a: ");
		scanf("%d", &a);
	}
	// Non va bene perché il valore viene preso dopo la condizione del while.
	return 0;
}