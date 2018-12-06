#include <stdio.h>

int main(){
	int n, i, s;
	scanf("%d %d", &n, &i);
	// Trovo il valore del contatore che andrò a decrementare.
	// n sarebbe il numero maggiore che meno il resto tra n e i dà sempre un valore intero.
	s = (n - (n%i))/i;
	// Eseguo il while fino a quando s è maggiore di 0 e nel corpo del while eseguo un decremento.
	while(s>0){
		printf("%d \t", (s*i));
		s--;
	}
	return 0;
}