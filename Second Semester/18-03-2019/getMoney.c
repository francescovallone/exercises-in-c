#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define M 3

int get_money(int rows, int cols, int array[rows][cols], int pos_x, int pos_y, int bt[rows][cols]);
int max(int a, int b);
static int memo[N][M];

int main(){
	int n=N, m=M, c;
	int array[n][m], bt[n][m];
	srand(time(NULL));
	printf("Money in each square: \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			array[i][j] = rand() % (m*n);
			bt[i][j] = 0;
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
	c = get_money(n, m, array, n-1, m-1, bt);
	printf("\n");
	for(int i=n-1; i>0;){
		for(int j=m-1; j>0;){
			if((memo[i][j] - array[i][j]) == memo[i-1][j]){
				bt[i][j] = 1;
				i--;
			}else{
				bt[i][j] = -1;
				j--;
			}
		}
	}
	printf("Backtrack of the array: \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%3d", bt[i][j]);
		}
		printf("\n");
	}
	printf("\nMax money gained: %d", c);
	return 0;
}

int get_money(int rows, int cols, int array[rows][cols], int pos_x, int pos_y, int bt[rows][cols]){
	if(memo[pos_y][pos_x] != 0){
		 return memo[pos_y][pos_x];
	}else if(pos_y==0 && pos_x==0){
		memo[pos_y][pos_x] = array[pos_y][pos_x];
		return memo[pos_y][pos_x];
	}else if(pos_x == 0){
		memo[pos_y][pos_x] = get_money(rows, cols, array, pos_x, pos_y-1, bt) + array[pos_y][pos_x];
		return memo[pos_y][pos_x];
	}else if(pos_y == 0){
		memo[pos_y][pos_x] = get_money(rows, cols, array, pos_x-1, pos_y, bt) + array[pos_y][pos_x];
		return memo[pos_y][pos_x];
	}else{
		memo[pos_y][pos_x] = max(get_money(rows, cols, array, pos_x, pos_y-1, bt), get_money(rows, cols, array, pos_x-1, pos_y, bt)) + array[pos_y][pos_x];
		return memo[pos_y][pos_x];
	}
}

int max(int a, int b){
	if(a<b){
		return b;
	}else{
		return a;
	}
}