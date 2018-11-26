#include <stdio.h>
#include <string.h>


void compare(char *s, char *t, int k);


int main(){
	char s[100] = "ciao  caro";
	char t[100] = "amico";
	int k = 5;
	compare(s, t, k);
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
