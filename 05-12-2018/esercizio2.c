#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int search(int* v, int s, int n);
int* order(int* v, int n);


int main(){
	int n=0, s;
	int* v;
	v = (int*) malloc(100*sizeof(int));
	while(scanf("%d", &v[n])){
		n++;
	}
	v = (int*) realloc(v ,n*sizeof(int));
	getchar();
	printf("Inserisci il numero che vuoi cercare: ");
	scanf("%d", &s);
	getchar();
	if(search(v, s, n)){
		printf("Il numero %d e' nell'array.", s);
	}else{
		printf("Il numero %d non e' nell'array", s);
	}
	free(v);
	return 0;
}


int* order(int* v, int n){
	int c, l, j;
	for (j = 0; j < n; j++){
		for (l = 0; l < n; l++){
			if (v[l] > v[j]){
				c = v[j];
				v[j] = v[l];
				v[l] = c;
			}
		}
	}
	return v;
}


int search(int* v, int s, int n){
	int f = 0, l = n-1, m = (f+l)/2, t=0;
	v = order(v, n);
	while(f <= l && !t){
		if(v[m] == s){
			t = 1;
		}else if(v[m] < s){
			f = m + 1;
		}else{
			l = m - 1;
		}
		if(f>l){
			return 0;
		}
		m = (f + l)/2;
	}
	return t;
}
