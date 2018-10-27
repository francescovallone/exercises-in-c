#include <stdio.h>


int main(){
	int k, i, j, s, r;
	scanf("%d", &k);
	// Trovo i punti vuoti della matrice
	for (i=1; i<k; i++){
		s += i;
	};
	// Trovo quanti valori assumerà la matrice triangolare inferiore
	r = k*k - s;
	// Stampo tutti i valori seguiti da ,
	for (j=1; j<=r; j++){
		printf("%d,", j);
	}
	return 0;
}
