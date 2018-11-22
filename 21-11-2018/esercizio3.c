#include <stdio.h>


int check(float *v, int i);


int main(){
	float v[100], m;
	int i=0;
	while(scanf("%f", &m)){
		v[i] = m;
		i++;
	}
	printf("%d \n", check(v, i));
	return 0;
}


int check(float *v, int i){
	int j, a=1;
	for(j = 1; j<i && a; j++){
		a = (v[j-1]<v[j]) ? 1 : 0;
	}
	return a;
}
