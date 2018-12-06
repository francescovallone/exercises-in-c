#include <stdio.h>

int main(){
	int n, i, s;
	scanf("%d", &n);
	// Per definizione anche se n = 0 il valore di s sarà sempre uno.
	s = 1;
	// Verifico che i sia minore o uguale ad n e nel caso in cui lo sia allora eseguo la moltiplicazione tra s e i
	for(i=1; i<=n; i++){
		s *= i;
	}
	printf("%d", s);
	return 0;
}