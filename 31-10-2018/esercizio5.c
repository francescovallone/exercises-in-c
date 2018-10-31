#include <stdio.h>

int main(){
	int k, j, i;
	scanf("%d", &k);
	// Stampo tutti i valori seguiti da ,
	for (j=1, i=1; j<=(k*k); j++, i+=1){
		if(i == k){
			printf("%d \n", j);
			i = 0;
		}else{
			printf("%d ", j);
		}
	}
	return 0;
}
