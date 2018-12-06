#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int minmax(int t, int* a, int n);
int* order(int t, int* a, int n);


int main(){
	int t, i;
	int* a;
	a = (int*) malloc(100*sizeof(int));
	i = 0;
	printf("Inserisci i valori dell'array: \n");
	while(scanf("%d", &a[i])){
		i++;
	}
	getchar();
	printf("Scegli un valore tra 0 e 1: ");
	scanf("%d", &t);
	getchar();
	a = (int*) realloc(a, i*sizeof(int));
	a = order(t, a, i);
	for(int l = 0; l<i; l++){
		printf("%d \t", a[l]);
	}
	free(a);
	return 0;
}


int* order(int t, int* a, int n){
	int r[n];
	for(int i=0; i<n; i++){
		r[i] = minmax(t, a, n-i);
	}
	for(int i=0; i<n; i++){
		a[i] = r[i];
	}
	return a;
}


int minmax(int t, int* a, int n){
	int flag = a[0];
	for(int i = 0; i<n; i++){
		if(t == 0 && a[i] < flag){
			flag = a[i];
		}else if(t == 1 && a[i] > flag){
			flag = a[i];
		}
	}
	int pos;
	for(int i=0; i<n; i++){
		if(a[i] == flag){
			pos = i;
		}
	}
	for(int c=pos; c<n; c++){
		a[c] = a[c+1];
	}
	return flag;
}
