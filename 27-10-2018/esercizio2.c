#include <stdio.h>

int main(){
	// inizializzo le variabili necessarie
	int n,r;
	double s, i;
	// Richiedo il valore della variabile n
	scanf("%d %d", &n, &r);
	for(i=r; i<n; i++){
		s += 1/i;
	}
	printf("%lf", s);
	return 0;
}

