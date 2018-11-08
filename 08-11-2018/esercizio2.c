#include <stdio.h>

int primo(int a);

int main(){
	int a, i;
	scanf("%d", &a);
	for(i = 2; i<=a;i++){
		if(primo(i)){
			printf("%d ", i);
		}
	}
	return 0;
}

int primo(int a){
	int i, j=0;
	for(i = 2; i<=a/2; i++){
		if(a%i == 0){
			j = 1;
			break;
		}
	}
	if(j == 0){
		return i;
	}
}
