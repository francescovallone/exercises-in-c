#include <stdio.h>

int main(){
	int a, m, c, d, u;
	scanf("%d", &a);
	// Stiamo lavorando con degli int, quindi anche dividendoli per 1000 ricaveremmo solo la parte intera
	m = a/1000;
	// Devo trovare le centinaia, quindi faccio il numero (a) meno le migliaia tutto fratto 100
	c = (a - (m*1000))/100;
	// Eseguo la stessa operazione di prima levando anche le centinaia e dividendo per 10
	d = (a - (m*1000) - (c*100))/10;
	// Eseguo la stessa operazione di prima levando anche le decine
	u = (a - (m*1000) - (c*100) - (d*10));
	printf("Migliaia = %d, Centinaia = %d, Decine = %d, Unita' = %d", m,c,d,u);
	return 0;
}