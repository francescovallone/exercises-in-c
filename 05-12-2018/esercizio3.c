#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** order_strings(int t, char** a, int n);


int main(){
	int t, i;
	char** a;
	char input[1000];
	printf("Inserisci la lunghezza dell'array: ");
	scanf("%d", &i);
	getchar();
	a = (char**) malloc(i*sizeof(char*));
	printf("Inserisci i valori dell'array: \n");
	for(int n = 0; n<i; n++){
		scanf("%[^\n]s", input);
		getchar();
		a[n] = malloc((strlen(input))*sizeof(char));
		strcpy(a[n], input);
	}
	printf("Scegli un valore tra 0 e 1: ");
	scanf("%d", &t);
	getchar();
	a = order_strings(t, a, i);
	for(int l = 0; l<i; l++){
		printf("%s \t", a[l]);
	}
	free(a);
	return 0;
}


char** order_strings(int t, char** a, int n){
	char* c[100];
	int l, j;
	if(!t){
		for (j = 0; j < n; j++){
			for (l = 0; l < n; l++){
				if (strcmp(a[l], a[j]) > 0){
					*c = a[j];
					a[j] = a[l];
					a[l] = *c;
				}
			}
		}
	}else{
		for (j = 0; j < n; j++){
			for (l = 0; l < n; l++){
				if (strcmp(a[l], a[j]) < 0){
					*c = a[j];
					a[j] = a[l];
					a[l] = *c;
				}
			}
		}
	}
	return a;
}
