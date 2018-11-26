#include <stdio.h>
#include <string.h>


void to_the_end(char *s, char *r);


int main(){
	char s[1000];
	char r[1000];
	to_the_end(s, r);
	printf("%s", r);
	return 0;
}


void to_the_end(char *s, char *r){
	char t[1000];
	int i, j;
	scanf("%[^\n]s", s);
	for(i = (strlen(s)-5), j=0; i < strlen(s); i++, j++){
		t[j] = s[i];	
	}
	t[5] = '\0';
	if(!(strcmp(t, "fine."))){
		r = strncpy(r, s, strlen(s)-5);
	}
}
