#include <stdio.h>
#include <stdlib.h>


void sum_vector(double *v, double *w, double *sum);
void print_vector(char *s, double *sum);


int main(){
	double *v, *w, *sum;
	v = calloc(5, sizeof(double));
	w = calloc(5, sizeof(double));
	sum = calloc(5, sizeof(double));
	sum_vector(v, w, sum);
	print_vector("Il vettore somma: ", sum);
	free(v);
	free(w);
	free(sum);
}


void sum_vector(double *v, double *w, double *sum){
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
		sum[j] = v[j] + w[j];
	}
}


void print_vector(char *s, double *sum){;
	int i;
	printf(s);
	printf("{");
	for(i=0; i < 5; i++){
		if(i != 4){
			printf("%lf, ", sum[i]);
		}else{
			printf("%lf", sum[i]);
		}
	}
	printf("}");
}
