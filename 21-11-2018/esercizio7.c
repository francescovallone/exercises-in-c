#include <stdio.h>

void asteriskize(int *v, int i);


int main(){
	int v[100], i=0;
	while(scanf("%d", &v[i])){
		i++;
	}
	asteriskize(v, i);
	return 0;
}


void asteriskize(int *v, int i){
	int l, n;
	for(l = 0; l<i;	l++){
		for(n = 0; n < v[l]; n++){
			printf("*");
		}
		printf("\n");
	}
}

