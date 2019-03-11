#include <stdio.h>


int fact(int n);


int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<=n; i++){
		printf("%d\n", fact(i));
	}
	return 0;
}


int fact(int n){
	if(n<=1){
		return 1;
	}
	return (n*fact(n-1));
}