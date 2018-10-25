#include <stdio.h>

int main(){
	int x = 20;
	while(x < 100){
		x += 26;
		printf("%d", x++);
	}
	// Stampera' una serie di numeri, in ordine: 46, 73, 100
	return 0;
}
