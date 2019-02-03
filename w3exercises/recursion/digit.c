#include <stdio.h>


int digits(int n);


int main(){
	int n;
	scanf("%d", &n);
	printf("%d",digits(n));
	return 0;
}


int digits(int n){
	static int r = 0;
	if(n == 0){
		return r;
	}else{
		r++;
		return digits(n/10);
	}
}