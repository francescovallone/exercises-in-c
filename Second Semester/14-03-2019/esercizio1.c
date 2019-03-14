#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mergeSort(int array[], int len, int (*compare)(int a, int b), int size);
void sortSubArray(int array[], int low, int high, int (*compare)(int a, int b), int size);
void merge(int array[], int left, int middle, int middle2, int right, int (*compare)(int a, int b), int size);
void insertionSort(int array[], int size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);
static clock_t vantage;

int main(){
	vantage = clock();
	int n;
	char c;
	scanf("%d", &n);
	getchar();
	int d[n];
	srand(time(NULL));
	for(int i = 0; i<n; i++){
		d[i] = rand() % n;
	}
	printf("\nDecidere se l'ordinamento e' di tipo crescente o decrescente [ '>' = Decrescente, '<' = Crescente ]: ");
	scanf("%c", &c);
	clock_t start = clock();
	if(c == '<'){
		mergeSort(d, n, ascending, n);
	}else{
		mergeSort(d, n, descending, n);
	}
	clock_t end = clock();
	for(int i=0; i<n; i++){
		printf("%d ", d[i]);
	}
	printf("\nTempo di esecuzione per %d elementi: %lf s. Il vantaggio dell'insertion e': %lf s", n, (double)(end-start)/CLOCKS_PER_SEC, (double)vantage/CLOCKS_PER_SEC);
	return 0;
}


void mergeSort(int array[], int len, int (*compare)(int a, int b), int size){
	if(len < 7){
		insertionSort(array, len, compare);
	}
	sortSubArray(array, 0, len-1, compare, size);
}

void sortSubArray(int array[], int low, int high, int (*compare)(int a, int b), int size){
	if((high-low)>= 1){
		size_t middle = (high+low)/2;
		size_t middle2 = middle+1;
		sortSubArray(array, low, middle, compare, size);
		sortSubArray(array, middle2, high, compare, size);
		merge(array, low, middle, middle2, high, compare, size);
	}
}

void merge(int array[], int left, int middle, int middle2, int right, int (*compare)(int a, int b), int size){
	int i, j, k;
	size_t leftIndex = left;
	size_t rightIndex = middle2;
	size_t combinedIndex = left;
	int temp[size];
	while (leftIndex <= middle && rightIndex <= right){ 
        if ((*compare)(array[leftIndex], array[rightIndex])){ 
            temp[combinedIndex++] = array[leftIndex++];
        }else{ 
			temp[combinedIndex++] = array[rightIndex++];
        }
    }
	if(leftIndex == middle2){
		while(rightIndex <= right){
			temp[combinedIndex++] = array[rightIndex++];
		}
	}else{
		while(leftIndex <= middle){
			temp[combinedIndex++] = array[leftIndex++];		
		}
	}
	for(i=left; i<=right; i++){
		array[i] = temp[i];
	}
}

int ascending(int a, int b){
	return a < b;
}

int descending(int a, int b){
	return a > b;
}

void insertionSort(int array[], int size, int (*compare)(int a, int b)){
	int c;
	int j = 0;
	clock_t start = clock(); 
	for (int i=1; i<size; i++){
		c = array[i];
		for (j=i-1; (j>=0) && (*compare)(array[j], c); j--){
			array[j+1]=array[j];
		}
		array[j+1]=c;
	}
	clock_t end = clock();
	vantage += (end-start);
}