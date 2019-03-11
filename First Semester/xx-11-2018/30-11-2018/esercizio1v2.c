#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sort_string(char* v[], int dim);

int main(){
	int size;
	scanf("%d", &size);
	char* v[size];
	printf("%d", sort_string(v, size));
	return 0;
}

int sort_string(char* v[], int dim){
	int c = 0, d = 0, i = 0, l;
	char input[1000];
	for(i=0; i<dim; i++){
		scanf("%s", input);
		v[i] = malloc((strlen(input)+1)*sizeof(char));
		strcpy(v[i], input);
	}
	for(i=0; i<dim-1; i++){
		if(*v[i] > *v[i+1]){
			c = 1;
		}else if(*v[i] < *v[i+1]){
			d = 1;
		}
	}
	for(l=0; l<dim; l++){
		free(v[l]); // AND I AM FREE, FREE FALLING
	}
	if(d != 0 && c == 0){
		return 1;
	}else if(d == 0 && c != 0){
		return -1;
	}
	return 0;
}
