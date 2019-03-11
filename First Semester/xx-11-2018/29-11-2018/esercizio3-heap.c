#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void compare(char *s, char *t, int k);


int main(){
	char *s;
	char *t;
	s = malloc(100*sizeof(char));
	t = malloc(100*sizeof(char));
	scanf("%[^\n]s", s);
	getchar();
	scanf("%[^\n]s", t);
	int k = 5;
	compare(s, t, k);
	free(s);
	free(t);
	return 0;
}


void compare(char *s, char *t, int k){
	char v[100];
	int i;
	strcpy(v, &s[k]);
	v[strlen(v)] = '\0';
	for(i=k; s[i] != '\0'; i++){
		s[i] = t[i-k];
	}
	strcat(s, v);
	printf("%s", s);
}
