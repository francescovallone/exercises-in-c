#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
#=========================================================================================#
#		Stesso esercizio del due ma senza l'uso di IF o cicli per controllare se		  #
#	il valore di j1 e di j2 sia minore o uguale alla lunghezza della rispettiva stringa.  #
#=========================================================================================#
*/

char* string_trans(int i1, int i2, int j1, int j2, char** s);


int main(){
	char** s;
	char input[1000];
	s = (char**) malloc(100*sizeof(char*));
	int flag = 1, r, i1, i2, j1, j2;
	for(r=0; flag;){
		scanf("%s", input);
		getchar();
		if(!strcmp("close", input)){
			flag = 0;
		}else{
			s[r] = (char*) malloc(strlen(input)*sizeof(char));
			strcpy(s[r], input);
			r++;
		}
	}
	s = (char**) realloc(s, r*sizeof(char*));
	flag = 1;
	printf("Digita la la posizione della prima stringa [1-%d]: ", r);
	scanf("%d", &i1);
	getchar();
	printf("Digita la posizione del carattere della prima stringa [1-%u]: ", strlen(s[i1-1]));
	scanf("%d", &j1);
	getchar();
	printf("Digita la posizione della seconda stringa [1-%d]: ", r);
	scanf("%d", &i2);
	getchar();
	printf("Digita la posizione del carattere della seconda stringa [1-%u]: ", strlen(s[i2-1]));
	scanf("%d", &j2);
	getchar();
	j1 = (int) (j1 - (j1%strlen(s[i1-1])))/strlen(s[i1-1]);
	j2 = (int) (j2 - (j2%strlen(s[i2-1])))/strlen(s[i2-1]);
	char *t = string_trans(i1-1, i2-1, j1, j2, s);
	printf("%s", t);
	free(t);
	while(r>=0){
		free(s[r]);
		r--;
	}
	free(s);
	return 0;
}


char* string_trans(int i1, int i2, int j1, int j2, char** s){
	char *t = malloc((j1+(strlen(s[i2])-j2))*sizeof(char));
	strncpy(t, s[i1], j1);
	t[j1+1] = '\0';
	strcat(t, &s[i2][j2]);
	return t;
}
