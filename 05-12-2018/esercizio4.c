#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int word_number(char* v, int n);
char* max_word(char* s, char* v);


int main(){
	char a[1000];
	char* s;
	scanf("%[^\n]s", a);
	getchar();
	printf("%d \n", word_number(a, strlen(a)));
	s = max_word(s, a);
	printf("La stringa di lunghezza maggiore e': %s", s);
	return 0;
}


char* max_word(char* s, char* v){
	char** r;
	int x = word_number(v, strlen(v)), l, d=0 ,t=0, i;
	r = (char**) malloc(x*sizeof(char*));
	for(i=0; i<x; i++){
		for(l=0; v[l] != ' '; l++){
			if(v[l+1] == ' ' && l != 0){
				r[i] = (char*) malloc((l+1)*sizeof(char));
				strncpy(r[i], v, l+1);
				r[i][l+1] = '\0';
			}
		}
		strcpy(v, &v[l+1]);
	}
	s = r[0];
	for(i=0; i<x; i++){
		if(strlen(s) < strlen(r[i])){
			s = r[i];
		}
	}
	free(r);
	return s;
}


int word_number(char* v, int n){
	int k = 0;
	for(int i = 0; i<n; i++){
		if(v[i] == ' ' && v[i+1] != '\0'){
			k++;
		}
	}
	return k+1;
}
