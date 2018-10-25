#include <stdio.h>

int main(){
	int x = 20;
	while(x++ < 100){
		x += 26;
	}
	printf("%d", x);
	return 0;
	// Stampera' solo 102
}