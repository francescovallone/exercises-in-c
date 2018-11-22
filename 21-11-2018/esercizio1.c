#include <stdio.h>


void indexing(int *v, int i);


int main(){
	int v[100], i=0, m;
	while(scanf("%d", &m)){
		v[i] = m;
		i++;
	}
	getchar();
	printf("%d", indexing(v, i));
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
