#include <stdio.h>

int main(){
	int x = 18;
	do{
		x = x - 2;
	}while(x+3>10);
	printf("%d", --x);
	// Stamperà solo 5
	return 0;
}