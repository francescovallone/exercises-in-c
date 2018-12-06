#include <stdio.h>

int main(){
	int k, j, r;
	scanf("%d", &k);
	k = k*k - ((k-1)*k)/2;
	// Stampo tutti i valori seguiti da ,
	for (j=1; j<=k; j++){
		printf("%d,", j);
	}
	return 0;
}
