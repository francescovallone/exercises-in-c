#include <stdio.h>

int main(){
	int a, b, i;
	scanf("%d %d", &a, &b);
	i = 0;
	do{
		i += 2;
		if(a > b){
			a -= b;
		}else if(a < b){
			b -= a;
		}
	}while(a != b);
	printf("%d", i);
	return 0;
}