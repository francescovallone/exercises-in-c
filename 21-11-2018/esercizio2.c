#include <stdio.h>


int check(int *v, int i);


int main(){
	int v[100], i=0, m;
	while(scanf("%d", &m)){
		v[i] = m;
		i++;
	}
	printf("%d \n", check(v, i));
	return 0;
}


int check(int *v, int i){
	int l, n=0;
	for(l=0; l<i; l++){
		n = v[l] == v[l-1] ? 1 : 0;
	}
	return n;
}