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
	int j, a=1, b = v[0];
	for(j = 1; j<i && a; j++){
		a = (b==v[j]) ? 1 : 0;
	}
	return a;
}
