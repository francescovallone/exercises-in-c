#include <stdio.h>

void crossover(int a, int b, int i, int *c, int *d);

int main(){
	int a, b, i, c, d;
	scanf("%d %d %d", &a, &b, &i);
	crossover(a, b, i, &c, &d);
	printf("%d, %d", c, d);
	return 0;
}

void crossover(int a, int b, int i, int *c, int *d){
	*c = b ^ (1 << (i-1));
	*d = a ^ (1 << (i-1));
}