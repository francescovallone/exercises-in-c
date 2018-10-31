#include <stdio.h>

int main(){
	int r, a, b, i;
	scanf("%d %d", &a, &b);
	r = 0;
	i = 0;
	do{
		i++;
		r = a%b;
		a = b;
		b = r;
	}while(r != 0);
	printf("%d", i);
	return 0;
}