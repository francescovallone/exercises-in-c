#include <stdio.h>

int main(){
	int a, i;
	char choose;
	scanf("%d %d %c", &a, &i, &choose);
	switch(choose){
		case 'c':
			// Eseguo l'operazione XOR per scambiare il valore al bit in posizione i
			a = a ^ 1 << (i-1);
			break;
		case 'z':
			// Eseguo l'operazione AND NOT per dare al bit in posizione i valore 0
			a = a & ~(1 << (i-1));
			break;
		case 'u':
			// Eseguo l'operazione OR per dare al bit in posizione i valore 1
			a = a | (1 << (i-1));
			break;
	}
	printf("Il nuovo valore di a e' %d", a);
	return 0;
}
