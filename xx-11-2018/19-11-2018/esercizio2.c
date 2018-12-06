#include <stdio.h>


/*
#
#	Questo esempio verifica anche quando il triangolo è rettangolo.
#	Per vedere l'esercizio che vuole fatto il professore lo trovate al link qui sotto.
#	https://github.com/vincenzocorso/exercises_c/blob/master/lez20/es2.c
#
*/


int main(){
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);
	if(b == a && c < b){
		printf("Non e' un triangolo.");
		return 0;
	}
	if(c < b && b > a){
		b = b ^ c;
		c = b ^ c;
		b = b ^ c;
	}else if(c < a && a > b){
		a = a ^ c;
		c = a ^ c;
		a = a ^ c;
	}
	if(c < a + b){
		if(a == b && b == c){
			printf("Il triangolo e' equilatero.");
		}else if(a == b){
			printf("Il triangolo e' isoscele.");
		}else if(c*c == (a*a) + (b*b)){
			printf("Il triangolo e' rettangolo.");
		}else{
			printf("Il triangolo e' scaleno.");
		}
	}
	return 0;
}
