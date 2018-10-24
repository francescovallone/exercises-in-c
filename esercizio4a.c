#include <stdio.h>

int main(){
	int a, b;
	// Prendo i valori interi di a e di b
	scanf("%d %d", &a, &b);
	// Eseguo lo scambio di variabile, mettiamo caso a sia 3 e b sia 1
	// a = 3 + 1 = 4, b = 4 - 1 = 3, a = 4 - 3 = 1
	a = a + b
	b = a - b
	a = a - b
	printf("I valori di A e di B adesso sono: a = %d, b = %d", a, b);
	return 0;
}