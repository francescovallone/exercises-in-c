#include <stdio.h>

int main(){
	int n, i, s;
	scanf("%d", &n);
	printf("Le coppie di numeri che moltiplicati danno %d sono: \n", n);
	// Trovo tutte le coppie di numeri che moltiplicate danno n.
	// Considero n/2 così da non contare per 2 volte le stesse coppie di numeri.
	// Controllo se il resto della divisione tra n e i sia uguale a 0 per avere solo numeri interi.
	for(i=2; i<=n/2; i++){
		if(n%i == 0){
			s = n / i;
			printf("(%d, %d)", i, s);
		}
	}
	return 0;
}