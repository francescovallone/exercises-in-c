#include <stdio.h>

int main(){
	int a;
	do{
		printf("Immetti a: ");
		scanf("%d", &a);
	}
	while(a%2 == 0);
	// Corretto.
	return 0;
}