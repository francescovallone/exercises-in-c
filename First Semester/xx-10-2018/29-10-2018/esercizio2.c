#include <stdio.h>

int main(){
	int n, i, s;
	// Prendo un numero intero N
	scanf("%d", &n);
	printf("I numeri pari fino a %d sono: \n", n);
	// Sapendo che 2n è sempre uguale ad un numero pari eseguo un for per n/2 così da fermarmi metà ciclo.
	for(i=1; i<=n/2; i++){
		s = 2*i;
		printf("%d \t", s);
	}
	return 0;
}