#include <stdio.h>
#include <stdlib.h>
#include "sortinglib.h"

extern int compare(void *a, void *b, char *s);

int main(){
	int i, N=10;
	int a[10] = {30, 20, 78, 19, 293, 194, 0, 12, 3, 7};
	int* d;
	void** v = (void**) malloc(N*sizeof(int*));
	for(i=0; i<N; i++){
		v[i] = &a[i];
	}
	bubble_sort(a, N, "int");
	for(i=0; i<N; i++){
		d = (int *) v[i];
		printf("%d ", *d);
	}
}

int compare(void *a, void *b, char *s){
	if(!strcmp(s, "double")){
		return compare_double((double*) a, (double*) b);
	}else if(!strcmp(s, "int")){
		return compare_int((int*) a, (int*) b);
	}else if(!strcmp(s, "float")){
		return compare_float((float*) a, (float*) b);
	}else if(!strcmp(s, "string")){
		return strcmp((char*) a, (char*) b);
	}
	return 0;
}