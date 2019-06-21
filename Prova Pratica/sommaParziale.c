#include <stdio.h>
#include <stdlib.h>


int* sommaParziale(int* v, int N){
	int* a = malloc(((N/2)+1)*sizeof(int));
	for(int i = 0; i<N/2; i++){
		*(a+i) = *(v+i) + *(v+(N-i-1));
	}
	*(a + (N/2)) = *(v + (N/2));
	return a;
}


int main(){
	int v[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 202};
	int N = sizeof(v)/sizeof(v[0]);
	int* a = sommaParziale(v, N);
	return 0;
}