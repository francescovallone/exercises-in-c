#include <stdio.h>

int main(){
	int a, b, n, c, l, m;
	scanf("%d", &n);
	// Eseguo due cicli con due variabili, la prima dipende da n e la seconda dipende dalla prima.
	for(m = 1; m < n; m++) { 
        for (l = 1; l < m; l++) {
        	// Le formule le ho prese da wikipedia e.e
        	a = (m*m) - (l*l);
		b = 2 * m * l;
		c =  (m*m) + (l*l);
		// Verifica se il valore della c supera il valore assegnato a n dall'utente, se si verifica la condizione salta quel valore.
            if (c > n){
            	break;
            }
            printf("%d %d %d\n", a, b, c); 
        } 
    } 
    return 0;
}
