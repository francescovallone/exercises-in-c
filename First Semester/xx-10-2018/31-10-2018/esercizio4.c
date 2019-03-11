#include <stdio.h>

/* ESERCIZIO CORRETTO */

int main(){
	int k, j, r, a=0;
	scanf("%d", &k);
	for(j = 1; j<=k; j++){
		for(r = 1; r <= j; r++){
			printf("%d", ++a);
			if(r == j){
				printf("\n");
			}
		}
	}
	return 0;
}
