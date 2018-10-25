#include <stdio.h>
#include <math.h>

int main(){
	int a,b,c;
	double delta, x1, x2;
	// Prendo i valori di a, b e c
	scanf("%d %d %d", &a, &b, &c);
	// Calcolo il delta che è uguale a radice di b^2 - 4ac
	delta = sqrt(pow(b, 2) - (4*a*c));
	// Trovo le due soluzioni -b + o - delta tutto fratto 2a
	x1 = (-b + delta)/(2*a);
	x2 = (-b - delta)/(2*a);
	printf("x1 = %lf e x2 = %lf", x1, x2);
	return 0;
}