#include <stdio.h>


int digits(int n);


int main(){
	int n;
	scanf("%d", &n);
	printf("%d",digits(n));
	return 0;
}


int digits(int n){
	if(!n){
		return 0;
	}
	return ((n%10) + digits(n/10));
}