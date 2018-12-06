#include <stdio.h>
#include <stdlib.h>

double* minmax(double v[4][2], double* mnx, int rows, int cols, int index[2][2]);

int main(){
	double v[4][2] = {
		{1, 2},
		{-12, 3},
		{-4.20, 12},
		{120, 4}
	};
	int index[2][2], rows = 4, cols = 2;
	double* mnx;
	mnx = (double*) calloc(2, sizeof(double));
	mnx = minmax(v, mnx, rows, cols, index);
	printf("Il valore minimo e' %lf", mnx[0]);
	printf("\nIl valore massimo e' %lf", mnx[1]);
	printf("\nL'indice del valore minimo e' {%d, %d}", index[0][0], index[0][1]);
	printf("\nL'indice del valore massimo e' {%d, %d}", index[1][0], index[1][1]);
	free(mnx);
	return 0;
}


double* minmax(double v[4][2], double* mnx, int rows, int cols, int index[2][2]){
	double max = v[0][0];
	double min = v[0][0];
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(max < v[i][j]){
        		max = v[i][j];
				index[1][0] = i;
				index[1][1] = j;
      		}
			if(min > v[i][j]){
				min = v[i][j];
				index[0][0] = i;
				index[0][1] = j;
			}
		}
	}
	mnx[0] = max;
	mnx[1] = min;
	return mnx;
}
