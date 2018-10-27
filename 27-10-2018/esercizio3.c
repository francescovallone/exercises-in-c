#include <stdio.h>


int main(){
	int k;
	double i, j, s, r;
	// Richiedo l'intero K all'utente
	scanf("%d", &k);
	// Eseguo il ciclo for con due variabili, due condizioni e due incrementi
	for (i=1, j=1; i < k && j<=i; i++, j+=1){
		r = r + 1/(i+j);
		s += r;
	}
	printf("%lf", s);
	return 0;
}
