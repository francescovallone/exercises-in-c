#include <stdio.h>
#include <math.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	// Faccio in modo di avere a sempre maggiore di b
	if(a < b){
		a = a + b
		b = a - b
		a = a - b
	}
	//Controllo se a sia uguale a b^3
	if(a == pow(b, 3)){
		printf("%d e' il cubo di %d", a, b);
	}else if(a == pow(b, 2)){ // Eseguo lo stesso controllo di prima ma per b^2
		printf("%d e' il quadrato di %d", a, b);
	}else{ // Viene eseguito quando nessuno dei due if ha la condizione vera
		printf("%d è minore di %d", a, b);
	}
	return 0;
}