#include <stdio.h>
#include <string.h>

void reverse(char* s, int n);
void bireverse(const char* const ptr);

int main(){
	char s[200], t[200];
	scanf("%s", s);
	reverse(s, 0);
	// bireverse(s);
	return 0;
}

void reverse(char* s, int n){
	if(n == (strlen(s)-n)){
		return;
	}else{
		char a = s[n];
		s[n] = s[strlen(s)-1-n];
		s[strlen(s)-1-n] = a;
		return reverse(s, n+1);
	}
}


void bireverse(const char* const ptr){
	if(*ptr == '\0'){
		return;
	}else{
		bireverse(ptr+1);
		printf("%c", *ptr);
	}
}