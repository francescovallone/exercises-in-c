#include <stdio.h>
#include <stdlib.h>


int* minmax(double* V, int n){
	int* t, minI;
	t = malloc(4*sizeof(int));
	double min = V[0], max = V[0], diff;
	for(int i = 0; i<n; i++){
		if(min > V[i]){
			min = V[i];
			minI = i;
			t[0] = i;
			t[2] = i;
			printf("%3d, %3d \n", t[0], t[2]);
		}else{
			t[0] = 0;
			t[2] = 0;
			minI = 0;
		}
		if(max < V[i]){
			max = V[i];
			t[3] = i;
		}else{
			t[3] = 0;
		}
	}
	diff = max - min;
	for(int i = 0; i<n; i++){
		if(i != minI && (diff > (V[i] - min))){
			diff = V[i] - min;
			t[1] = i;
		}
	}
	return t;
}



int main(){
	double V[] = {1.2,1.4,1.7,2};
	int N = 4;
	int* t = minmax(V, N);
	for(int i = 0; i<4; i++){
		printf("%3d", t[i]);
	}
}