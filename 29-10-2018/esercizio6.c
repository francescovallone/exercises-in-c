#include <stdio.h>

int main(){
	int n, i;
	scanf("%d", &n);
	i = 0;
	// Per trovare la radice verifico che il quadrato di i+1 sia minore o uguale a n
	// Se lo è allora aumento il contatore altrimenti printo direttamente il valore i
	while((i+1)*(i+1)<=n){
		i++;
	}
	printf("%d", i);
	return 0;
}