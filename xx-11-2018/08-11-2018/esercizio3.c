#include <stdio.h>

void sep(int n);

int main(){
	int n, i;
	scanf("%d", &n);
	sep(n);
	return 0;
}

void sep(int n){
	int d = 1, temp, q;
	for(temp = n; temp != 0, temp /= 10; d *= 10);
	if(n < 0){
		printf("-");
		n = -n;
	}
	while(d > 0){
		q = n / d;
		printf("%d \t", q);
		n = n - q*d;
		d /= 10;
	}
}
