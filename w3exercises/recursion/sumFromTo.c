#include <stdio.h>


int sumTo(int n);


int main(){
	int n;
	scanf("%d", &n);
	printf("%d", sumTo(n));
	return 0;
}


int sumTo(int n){
	int t;
	if(n == 1){
		return 1;
	}else{
		// @ts-ignore
		t = n + sumTo(n-1);
	}
	return t;
}