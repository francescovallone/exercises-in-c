#include <stdio.h>
#include <string.h>


void make_palindrome_great_again(char *s);


int main(){
	char s[100] = "ciao";
	make_palindrome_great_again(s); // oaiciao
	return 0;
}


void make_palindrome_great_again(char *s){
	int i, f;
	char t[1000] = "";
	for(i=strlen(s); i>0; i--){
		if(s[i] != s[strlen(s)+i]){
			t[strlen(t)] = s[i];
		}
	}
	strcat(t, s);
	printf("%s", t);
}
