#include <stdio.h>

int main(){
	int n, i, s;
	// Prendo un numero intero N
	scanf("%d", &n);
	printf("I numeri dispari fino a %d sono: \n", n);
	// Sapendo che 2n - 1 è sempre uguale ad un numero dispari eseguo un for per n/2 così da fermarmi metà ciclo.
	for(i=1; i<=n/2; i++){
		s = (2*i) - 1;
		printf("%d \t", s);
	}
	return 0;
}