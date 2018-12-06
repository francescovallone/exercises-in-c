/* 
	Esercizio fatto con l'ausilio di libmatrix, libreria creata da Vincenzo Corso.
	Link: https://github.com/vincenzocorso/libmatrix
*/


#include <stdio.h>
#include <stdlib.h>


void swap(int cols, int v[][cols], int i, int j); //PRENDETE LA PILLOLA ROSSA:
void print_matrix(int cols, int rows, int v[][cols]);


int main(){
	int v[4][2] = {
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8}
	};
	int i, j, c = 2, r = 4;
	printf("Scegli la prima riga [1 - 4]: ");
	scanf("%d", &i);
	getchar();
	printf("Scegli la seconda riga [1 - 4]: ");
	scanf("%d", &j);
	getchar();
	swap(c, v, i-1, j-1);
	print_matrix(c, r, v);
	return 0;
}


void swap(int cols, int v[][cols], int i, int j){
	int c;
	for (int l = 0; l < cols; l++){
		c = v[i][l];
		v[i][l] = v[j][l];
		v[j][l] = c;
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
