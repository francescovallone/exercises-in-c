#include <stdio.h>

int main(){
	int a, j, i;
	scanf("%d", &a);
	for(i = 2; i<=a;){
		for(j = 2; j<=i; j++){
			if(i%j == 0){
				break;
			}
		}
		if(i == j){
			printf("%d \n", i);
		}
		i++;
	}
	return 0;
}
