#include <stdio.h>
#include <string.h>

size_t findMinimum(int* array, size_t len);
void selectionSort(int* array, size_t len);
void iterative(int* array, size_t len);

int main(){
	int array[5] = {5,2,3,1,4};
	int len = sizeof(array)/sizeof(array[0]);
	selectionSort(array, len);
	for(int i=0; i<len; i++){
		printf("%d", array[i]);
	}
	return 0;
}

size_t findMinimum(int* array, size_t len){
	if(len == 1){
		return 0;
	}else{
		int min = 1 + findMinimum(array + 1, len-1);
		if(array[min] < array[0]){
			return min;
		}else{
			return 0;
		}
	}
}

void selectionSort(int* array, size_t len){
	if (len == 1){
		return;
	}else{
		int c;
		size_t min = 1 + findMinimum(array+1, len-1);
		if(array[0] > array[min]){
			c = array[0];
			array[0] = array[min];
			array[min] = c;
		}
		selectionSort(array+1, len-1);
	}
}

void iterative(int* array, size_t len){
	int c, min;
	for(int i=0; i<len; i++){
		min = i + findMinimum(array+i, len-i);
		if(min != i){
			c = array[i];
			array[i] = array[min];
			array[min] = c;
		}
	}
}