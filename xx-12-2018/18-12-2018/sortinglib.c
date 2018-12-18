#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_double(double *a, double *b){
	if(*a > *b){
		return 1;
	}else if(*a < *b){
		return -1;
	}else{
		return 0;
	}
}

int compare_float(float *a, float *b){
	if(*a > *b){
		return 1;
	}else if(*a < *b){
		return -1;
	}else{
		return 0;
	}
}

int compare_int(int *a, int *b){
	if(*a > *b){
		return 1;
	}else if(*a < *b){
		return -1;
	}else{
		return 0;
	}
}

void simple_sort(void **v, int dim, char* type){
	void *c;
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++){
			if(compare(v[j], v[i], type) > 0){
				c = v[i];
				v[i] = v[j];
				v[j] = c;
			}
		}
	}
}

void sel_sort(void **v, int dim, char* type){
	void *c;
	int m;
	for(int i=0; i<dim; i++){
		m = i;
		for(int j=0; j<dim; j++){
			if(compare(v[j], v[m], type) > 0){
				m = j;
			}
			if(m != i){
				c = v[i];
				v[i] = v[m];
				v[m] = c;
			}
		}
	}
}

void ins_sort(void **v, int dim, char* type){
	void* c;
	int j = 0;
	for (int i=1; i<dim; i++){
		c = v[i];
		for (j=i-1; (j>=0) && compare(v[j], c, type) > 0; j--){
			v[j+1]=v[j];
		}
		v[j+1]=c;
	}
}

void bubble_sort(void **v, int dim, char* type){
	void* c;
	int swap = 1;
	while(swap){
		swap = 0;
		for(int i=0; i<dim-1; i++){
			if(compare(v[i], v[i+1], type) > 0){
				c = v[i];
				v[i] = v[i+1];
				v[i+1] = c;
				swap = 1;
			}
		}
	}
}
