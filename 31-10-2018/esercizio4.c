#include <stdio.h>

int main(){
	int k, j, r;
	scanf("%d", &k);
	r = k*k - ((k-1)*k);
	// Stampo tutti i valori seguiti da ,
	for (j=1; j<=r; j++){
		printf("%d,", j);
	}
	return 0;
}
