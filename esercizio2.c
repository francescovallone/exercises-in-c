#include <stdio.h>

int main(){
	int a;
	// Prende il valore dell'intero "a"
	scanf("%d", &a);
	// Controllo che a non sia maggiore di 100
	if(a => 100){
		printf("Scegli un numero minore di 100");
	}else{
		if(a => 90){
			printf("A");
		}else if(a => 80 && a < 90){
			printf("B");
		}else if(a => 70 && a < 80){
			printf("C");
		}else if(a > 60 && a < 70){
			printf("D");
		}else{
			printf("F");
		}
	}
	return 0;
}