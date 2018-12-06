#include <stdio.h>
#include <string.h>


void dxtosx(char *s, char *t);


int main(){
	char s[100];
	char t[100];
	scanf("%[^\n]s", s);
	dxtosx(s, t);
	printf("%s", t);
	return 0;
}


void dxtosx(char *s, char *t){
	int r;
	for(r=0; r < strlen(s); r++){
		t[r] = s[(strlen(s)-1)-r];
	}
}
