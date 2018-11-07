#include <stdio.h>


int main(){
	int a, i, d, r;
	// Prendo i valori di a e di i
	scanf("%d %d", &a, &i);
	// Eseguo una divisione usando lo shift
	d = a >> i;
	r = a - (d << i);
	printf("Il quoziente e' %d e il resto e' %d", d, r);
	return 0;
}
