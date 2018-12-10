#include <stdio.h>
#include <string.h>


void compare(char *s, char *t);


int main(){
	char s[100] = "ciaociao";
	char t[100] = "cio";
	compare(s, t);
	return 0;
}


void compare(char *s, char *t){
	int i, r;
	for(r=0;r < strlen(t); r++){
		for(i=0; i<strlen(s); i++){
			if(s[i] == t[r]){
				strcpy(&s[i], &s[i+1]);
			}
		}
	}
	
	printf("%s \n", s);
}
