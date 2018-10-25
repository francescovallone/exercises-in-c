#include <stdio.h>

int main(){
	int x = 18;
	do{
		x = x - 2;
	}while(x>10);
	x = x + 3;
	printf("%d", x);
	// Stamperà solo 13
	return 0;
}