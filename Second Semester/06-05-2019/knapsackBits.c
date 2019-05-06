#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ITEMS 5
#define WEIGHT 20
#define MAX 20


static int dpTable[ITEMS][WEIGHT];
static int dpArray[ITEMS];


typedef struct item{
	int value;
	int weight;
} item;


int knapsackRecursive(item items[], int n, int knapsize);
void getElements(item items[], int n, int knapsize, int result);
int max(int a, int b);
void print_dpTable(int n, int w);


int main(){
	item items[ITEMS];
	int knapsize = WEIGHT, value;
	srand(time(NULL));
	for(int i=0; i<ITEMS; i++){
		items[i].value = rand() % MAX;
		items[i].weight = 1 + rand() % WEIGHT;
		printf("{ %2d, %2d }, ", items[i].value, items[i].weight);
	}
	printf("\n");
	value = knapsackRecursive(items, ITEMS, knapsize);
	print_dpTable(ITEMS, knapsize);
	getElements(items, ITEMS, knapsize, value);
	printf("\nValore rubato = %d", value);
	return 0;
}


int knapsackRecursive(item items[], int n, int knapsize){
	if(knapsize <= 0 || n == 0) return 0;
	if(items[n-1].weight > knapsize) return knapsackRecursive(items, n-1, knapsize);
	if(dpTable[n-1][knapsize - items[n-1].weight] == 0) dpTable[n-1][knapsize - items[n-1].weight] = knapsackRecursive(items, n-1, knapsize - items[n-1].weight);
	if(dpTable[n-1][knapsize] == 0){
		dpTable[n-1][knapsize] = knapsackRecursive(items, n-1, knapsize);
		return max(dpTable[n-1][knapsize-items[n-1].weight] + items[n-1].value, dpTable[n-1][knapsize]);
	}
}



void getElements(item items[], int n, int knapsize, int result){
	int ks = knapsize;
	for(int i = n; i > 0 && result > 0; i--){
		printf("0");
		if(result == (dpTable[i-1][ks-items[i-1].weight] + items[i-1].value)){
			printf("1");
			result -= items[i-1].value;
			ks -= items[i-1].weight;
		}
	}
}


void print_dpTable(int n, int w){
	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < w; j++){
			printf("%3d ", dpTable[i][j]);
		}
		printf("\n");
	}
	
}

int max(int a, int b){
	if(a<b){
		return b;
	}
	return a;
}