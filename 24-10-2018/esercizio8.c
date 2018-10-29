#include <stdio.h>
#include <math.h>

int main(){
	int a, i, n, d, r;
	// Prendo i valori di a e di i
	scanf("%d %d", &a, &i);
	n = pow(2,i);
	// Calcolo il resto tra il divisore e il dividendo
	// Faccio in modo che la divisione da adesso in poi dia resto 0 quindi sottraggo al divisore il resto
	// Eseguo una divisione usando lo shift
	d = a >> i;
	r = a << d;
	printf("Il quoziente e' %d e il resto e' %d", d, r);
	return 0;
}
