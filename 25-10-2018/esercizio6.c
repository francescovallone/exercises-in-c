#include <stdio.h>

int main(){
	int x = 18;
	do{
		x = x - 2;
		printf("%d", x++);
	}while(x>10);
	x = x + 3;
	// Stamperà una serie di numeri: 16, 15,14,13,12,11,10,9
	return 0;
}