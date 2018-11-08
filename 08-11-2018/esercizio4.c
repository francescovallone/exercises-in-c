#include <stdio.h>
#define XOR(A,B) (A & ~B)|(B & ~A)

void swap(int *a, int *b);

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("%d, %d", a, b);
	return 0;
}

void swap(int *a, int *b){
	*a = XOR(*a,*b);
	*b = XOR(*a,*b);
	*a = XOR(*a,*b);
}