#include <stdio.h>
#include <stdlib.h>


void add_sort(float *v, int dim, float a);
void print_vector(const char *s, const float *v, const int dim);

int main(){
	float *v, a;
	v = calloc(100, sizeof(float));
	int i=0;
	while(scanf("%f", &v[i])){
		i++;
	}
	v = realloc(v, (i+1)*sizeof(float));
	getchar();
	printf("Scrivi un numero che verra' aggiunto all'array: ");
	scanf("%f", &a);
	add_sort(v, i, a);
	print_vector("Il vettore risultante e': ", v, i+1);
	free(v);
}


void add_sort(float *v, int dim, float a){
	// Sort
	float tmp;
	int j, l;
	v[dim] = a;
	for (j = 0; j < dim+1; j++){
		for (l = 0; l < dim+1; l++){
			if (v[l] > v[j]){
				tmp = v[j];
				v[j] = v[l];
				v[l] = tmp;
			}  
		}
	}
}


void print_vector(const char *s, const float *v, const int dim){
	int i;
	printf("%s", s);
	printf("{");
	for(i=0; i < dim; i++){
		if(i != dim-1){
			printf("%f, ", v[i]);
		}else{
			printf("%f", v[i]);
		}
	}
	printf("}");
}
