#include <stdio.h>

int main(){
	float a,b;
	char c;
	printf("Scrivi due numeri e l'operazione da eseguire. ");
	scanf("%f %f %c", &a, &b, &c);
	switch(c){
		case '+':
			printf("%f", (a+b));
			break;
		case '-':
			printf("%f", (a-b));
			break;
		case '*':
			printf("%f", (a*b));
			break;
		case '/':
			if(a == 0 || b == 0){
				printf("Non posso eseguire la divisione");
			}else{
				printf("%f", (a/b));
			}
			break;
	}
	return 0;
}