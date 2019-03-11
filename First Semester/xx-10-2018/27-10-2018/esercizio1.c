#include <stdio.h>

int main(){
	// inizializzo le variabili necessarie
	int i,n;
	// Richiedo il valore della variabile n
	scanf("%d", &n);
	for(i=0; n>0; i++){
		n = n/2;
	}
	printf("%d", i);
	return 0;
}

