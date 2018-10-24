#include <stdio.h>
#include <math.h>

int main(){
	int a, i, n, d, r, q;
	// Prendo i valori di a e di i
	scanf("%d %d", &a, &i);
	n = pow(2,i);
	// Calcolo il resto tra il divisore e il dividendo
	r = a%n;
	// Faccio in modo che la divisione da adesso in poi dia resto 0 quindi sottraggo al divisore il resto
	d = a - r;
	// Eseguo una divisione usando lo shift
	d = d >> i;
	printf("Il quoziente e' %d e il resto e' %d", d, r);
	return 0;
}
