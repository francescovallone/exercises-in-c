#include <stdio.h>

void asteriskize(int *v, int i);


int main(){
	int v[100], i=0, m;
	while(scanf("%d", &m)){
		v[i] = m;
		i++;
	}
	asteriskize(v, i);
	return 0;
}


void asteriskize(int *v, int i){
	int l, n, c;
	for(l = 0; l<i;){
		c = v[l];
		for(n = 0; n < c; n++){
			printf("*");
		}
		printf("\n");
		l++;
	}
}

