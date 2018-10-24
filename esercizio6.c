#include <stdio.h>

int main(){
	int a, b, r;
	scanf("%d %d", &a, &b);
	// Essendo b <= logaritmo in base 2 di a una disequazione
	// Posso affermare che 2^b sia il valore di a
	// Quindi eseguo una moltiplicazione usando lo shift (1 * 2^b) e controllo che questa sia minore o uguale ad a
	r = 1 << b;
	if(r <= a){
		printf("VERO");
	}else{
		printf("FALSO");
	}
	return 0;
}
