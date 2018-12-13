#include <stdio.h>
#include <stdlib.h>


void swap(int cols, int rows, int v[][cols], int i, int j);
void print_matrix(int cols, int rows, int v[][cols]);


int main(){
	int v[2][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8}
	};
	int i, j, c = 4, r = 2;
	printf("Scegli la prima colonna [1 - 4]: ");
	scanf("%d", &i);
	getchar();
	printf("Scegli la seconda colonna [1 - 4]: ");
	scanf("%d", &j);
	getchar();
	swap(c, r, v, i-1, j-1);
	print_matrix(c, r, v);
	return 0;
}


void swap(int cols, int rows, int v[][cols], int i, int j){
	int c;
	for (int l = 0; l < rows; l++){
		c = v[l][j];
		v[l][j] = v[l][i];
		v[l][i] = c;
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
