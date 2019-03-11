#include <stdio.h>

int main(){
	int a;
	do{
		printf("Immetti a: ");
		scanf("%d", &a);
	}
	while(a%2);
	// Viene eseguita l'immissione ma il programma si ferma subito dopo perché la condizione del while non prevede un confronto
	return 0;
}