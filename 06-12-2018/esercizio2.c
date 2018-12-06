/* 
	Esercizio fatto con l'ausilio di libmatrix, libreria creata da Vincenzo Corso.
	Link: https://github.com/vincenzocorso/libmatrix
*/


#include <stdio.h>
#include <stdlib.h>


void matrix(int rows1, int cols1, int v[][cols1], int rows2, int cols2, int t[][cols2], int result[][cols2]); //PRENDETE LA PILLOLA ROSSA:
void print_matrix(int cols, int rows, int v[][cols]);


int main(){
	int v[4][2] = {
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8}
	};
	int t[2][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8}
	};
	int result[4][4], rows1 = 4, cols1 = 2, rows2 = 2, cols2 = 4;
	matrix(rows1, cols1, v, rows2, cols2, t, result);
	print_matrix(cols2, rows1, result);
	return 0;
}


void matrix(int rows1, int cols1, int v[][cols1], int rows2, int cols2, int t[][cols2], int result[][cols2]){
	int s=0;
	for(int i = 0; i<rows1; i++){
		for(int j = 0; j<cols2; j++){
			for(int k = 0; k<cols1; k++){
				s += v[i][k] * t[k][j];
			}
			result[i][j] = s;
			s = 0;
		}
	}
}


void print_matrix(int cols, int rows, int v[][cols]){
	printf("La matrice risultante e': \n");
	for(int i=0; i<rows; i++){
		printf("|");
		for(int j=0; j<cols; j++){
			if(j != cols-1){
				printf("%d, ", v[i][j]);
			}else{
				printf("%d", v[i][j]);			
			}
		}
		printf("|\n");
	}
}
