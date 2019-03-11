#include <stdio.h>


int fibo(int n);


int main(){
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;
}


int fibo(int n){
	if(n<=1){
		return n;
	}else{
		return (fibo(n-1) + fibo(n-2));
	}
}