#include <stdio.h>


void merge(int array[], int left, int middle, int middle2, int right, int size);
void bottomUp(int array[], int size);
int min(int a, int b){
	int c = (a<b) ? a : b;
	return c;
}


int main(){
	int array[10] = {1,0,15,9,3,6,4,21,8,11};
	bottomUp(array, 10);
	for(int i=0; i<10; i++){
		printf("%d ", array[i]);
	}
	return 0;
}


// Si ringrazia per la collaborazione Vincenzo Corso
void bottomUp(int array[], int size){
	for(int i=1; i<size; i*=2){
		for(int j=0; j<size; j+=i*2){
			merge(array, j, j+i-1, j+i, min(j+i*2-1, size-1), size);
		}
	}
}


void merge(int array[], int left, int middle, int middle2, int right, int size){
	size_t leftIndex = left;
	size_t rightIndex = middle2;
	size_t combinedIndex = left;
	int temp[size];
	while (leftIndex <= middle && rightIndex <= right){ 
        if (array[leftIndex] < array[rightIndex]){ 
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
	for(int i=left; i<=right; i++){
		array[i] = temp[i];
	}
}