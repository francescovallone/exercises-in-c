#include <stdio.h>

int main(){
	int a;
	printf("Immetti a: ");
	scanf("%d", &a);
	while(a%2){
		printf("Immetti a: ");
		scanf("%d", &a);
	}
	// Non va bene perché il while non esegue un confronto fra il risultato di a%2 e qualcos'altro.
	return 0;
}