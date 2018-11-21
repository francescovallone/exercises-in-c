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
	int l, n=0;
	for(l=0; l<i; l++){
		if(v[l] >= v[l-1]){
			n = 1;
		}else{
			return 0;
		}
	}
	if(n) return 1;
}
