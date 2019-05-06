#include <stdio.h>
#define BIT 4 * sizeof( int )

void displayBits(int number);

int main(){
	displayBits(-2);
	displayBits(-2 << 2);
	return 0;
}

void displayBits(int number){
	int mask = 1 << BIT - 1;
	for(int i = 1; i <= BIT; ++i){
		putchar(number & mask ? '1' : '0');
		number <<= 1;
		if(i % 4 == 0) putchar(' ');
	}
	putchar('\n');
}