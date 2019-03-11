#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int *find_char(char* string, char c);


int main(){
	char string[200] = "viva la mamma ed il papa";
	char c = 'a';
	int* v = (int*) calloc(1, sizeof(int));
	v = find_char(string, c);
	free(v);
	return 0;
}


int *find_char(char* string, char c){
	int* v = (int*) calloc(1, sizeof(int));
	for(int i = 0, j = 0; i<strlen(string); i++){
		if(string[i] == c){
			v = realloc(v, (j+1)*sizeof(int));
			v[j] = i;
			printf("%d ", v[j]);
		}
	}
	return v;
}