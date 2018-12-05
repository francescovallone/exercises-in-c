#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sort_string(char* v[], int dim, int *s);
void print_vector(const char *s, const int *v, const int dim);

int main(){
	int size, *s;
	scanf("%d", &size);
	s = malloc((size-1)*sizeof(int));
	char* v[size];
	sort_string(v, size, s);
	print_vector("Il vettore e': ", s, size);
	free(s);
	return 0;
}

void sort_string(char* v[], int dim, int *s){
	int c = 0, d = 0, i = 0, l;
	char input[1000];
	for(i=0; i<dim; i++){
		scanf("%s", input);
		v[i] = malloc((strlen(input)+1)*sizeof(char));
		strcpy(v[i], input);
	}
	for(i=0; i<dim-1; i++){
		if(strcmp(v[i], v[i+1]) < 0){
			s[i] = 1;
		}else if(strcmp(v[i], v[i+1]) > 0){
			s[i] = -1;
		}else{
			s[i] = 0;
		}
	}
	for(l=0; l<dim; l++){
		free(v[l]); // AND I AM FREE, FREE FALLING!
	}
}

void print_vector(const char *s, const int *v, const int dim){
	int i;
	printf("%s", s);
	printf("{");
	for(i=0; i < dim-1; i++){
		if(i != dim-2){
			printf("%d, ", v[i]);
		}else{
			printf("%d", v[i]);
		}
	}
	printf("}");
}
