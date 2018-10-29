#include <stdio.h>

int main(){
	int n, i, s;
	scanf("%d", &n);
	printf("Le coppie di numeri che sommati danno %d sono: \n", n);
	// Trovo tutte le coppie di numeri che sommate danno n.
	// Considero n/2 così da non contare per 2 volte le stesse coppie di numeri.
	for(i=1; i<=n/2; i++){
		s = n - i;
		printf("(%d, %d)", i, s);
	}
	return 0;
}