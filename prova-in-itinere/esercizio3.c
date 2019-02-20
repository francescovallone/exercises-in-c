#include <stdio.h>
#include <string.h>
#include <math.h>

int converti(char *t){
	int r = 0, c;
	for(int i=0; i<strlen(t); i++){
		c = *(t+i) - '0';
		r += c*pow(10, (strlen(t) - 1 - i));
	}
	return r;
}

int main(){
	char t[200];
	scanf("%s", t);
	printf("%d", converti(t));
	return 0;
}