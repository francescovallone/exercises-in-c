#include <stdio.h>


int count(int n);


int main(){
	count(1);
	return 0;
}


int count(int n){
	if(n <= 50){
		printf("%d ", n);
		count(n+1);
	}else{
		return n;
	}
}