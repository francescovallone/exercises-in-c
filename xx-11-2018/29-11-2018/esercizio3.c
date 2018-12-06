#include <stdio.h>
#include <stdlib.h>


void max_min(double *v, int dim, float *M, float *m, int *indM, int *indm);


int main(){
	double *v;
	v = calloc(100, sizeof(double));
	float *M, *m;
	M = calloc(1, sizeof(float));
	m = calloc(1, sizeof(float));
	int i=0, *indM, *indm;
	indM = calloc(1, sizeof(int));
	indm = calloc(1, sizeof(int));
	while(scanf("%lf", &v[i])){
		i++;
	}
	max_min(v, i, M, m, indM, indm);
	printf("Il valore massimo e' %f e la sua posizione e' %d \n", M[0], indM[0]);
	printf("Il valore minimo e' %f e la sua posizione e' %d", m[0], indm[0]);
	free(v);
	free(M);
	free(m);
	free(indM);
	free(indm);
}


void max_min(double *v, int dim, float *M, float *m, int *indM, int *indm){
	int j, index=0;
	float min, max;
	max = M[0];
	for(j=0; j<dim; j++){
		if(v[j] > max){
			max = v[j];
			index = j;
		}
	}
	M[0] = max;
	indM[0] = index;
	min = v[0];
	index = 0;
	for(j=0; j<dim; j++){
		if(v[j] < min){
			min = v[j];
			index = j;
		}
	}
	m[0] = min;
	indm[0] = index;
}
