#include <stdio.h>

int main(){
	int x = 10, y = 0;
	do{
		x = x - 1;
		y = y + 1;
	}while(y<x);
	// Il valore della x diventa 5
	return 0;
}