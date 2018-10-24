#include <stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	a = (a & ~b)|(b & ~a);
	b = (a & ~b)|(b & ~a);
	a = (a & ~b)|(b & ~a);
	printf("I valori di A e di B adesso sono: a = %d, b = %d", a, b);
	return 0;
}