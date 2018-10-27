#include <stdio.h>

int main(){
	int i = 6, a = 12;
	while(i--){
		if(!a%i){
			printf("%d", i);
		}
	}
	// L'if controlla se non è il resto di a/i, Sbagliato.
	return 0;
}