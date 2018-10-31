#include <stdio.h>

int main(){
	int n = 0, i = 0, t = 0;
	double s;
	// Il ciclo funziona fino a quando lo scanf non riporta un valore negativo.
	// Se il valore è positivo allora aumenta il contatore e somma la t con il valore preso dallo scanf.
	// La media è la somma di tutti i numeri diviso quanti numeri sto considerando.
	// t è la somma dei numeri e i sono i numeri che vado a considerare.
	while(n>=0){
		scanf("%d", &n);
		if(n >= 0){
			i++;
			t += n;
		}
	}
	s = (double) t / i;
	printf("%lf", s);
}