#include <stdio.h>
#include <stdlib.h>


double vector(double *v, double *w);


double main(){
	double *v, *w;
	v = calloc(5, sizeof(double));
	w = calloc(5, sizeof(double));
	printf("%f", vector(v,w));
	free(v);
	free(w);
	return 0;
}


double vector(double *v, double *w){
	double sum=0;
	int i = 5, j = 0;
	printf("Inserisci i valori del primo vettore: \n");
	while(j < i){
		scanf("%lf", &v[j]);
		j++;
	}
	j=0;
	getchar();
	printf("Inserisci i valori del secondo vettore: \n");
	while(j < i){
		scanf("%lf", &w[j]);
		j++;
	}
	for(j=0; j<i; j++){
		sum += v[j]*w[j];
	}
	return sum;
}
