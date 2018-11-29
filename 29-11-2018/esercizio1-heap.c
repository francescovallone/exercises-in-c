#include <stdio.h>
#include <stdlib.h>


int indexing(int *v, int i);


int main(){
	int *v;
	v = malloc(1*sizeof(int));
	int i=0;
	while(scanf("%d", &v[i])){
		i++;
		v = realloc(v, i*sizeof(int));
	}
	getchar();
	printf("%d", indexing(v, i));
	free(v);
	return 0;
}


int indexing(int *v, int i){
	int l, n, flag=0;
	printf("Scegli il valore da verificare: ");
	scanf("%d", &n);
	for(l=0; l<i; l++){
		if(v[l] == n){
			flag = 1;
			return l;
		}
	}
	if(!flag){
		return 	-1;	
	}
}
