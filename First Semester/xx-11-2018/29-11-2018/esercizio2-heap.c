#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void dxtosx(char *s, char *t);


int main(){
	char *s, *t;
	s = malloc(100*sizeof(char));
	t = malloc(1*sizeof(char));
	scanf("%[^\n]s", s);
	dxtosx(s, t);
	printf("%s", t);
	free(s);
	free(t);
	return 0;
}


void dxtosx(char *s, char *t){
	int r;
	for(r=0; r < strlen(s); r++){
		t = realloc(t, (r+1)*sizeof(char));
		t[r] = s[(strlen(s)-1)-r];
	}
	t[strlen(t)-1] = '\0';
}
