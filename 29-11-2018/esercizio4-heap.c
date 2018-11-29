#include <stdio.h>
#include <string.h>


void make_palindrome_great_again(char *s);
void add_char(char *s, int pos, char c);


int main(){
	char *s;
	s = malloc(100*sizeof(char));
	scanf("%s", s);
	make_palindrome_great_again(s);
	printf("%s", s);
	free(s);
	return 0;
}


void add_char(char *s, int pos, char c){
	char *p = s + pos, *b;
	b = malloc((strlen(s)+1)*sizeof(char));
	strcpy(b, p);
	s[pos] = c;
	strcpy(p+1, b);
	free(b);
}


void make_palindrome_great_again(char *s){
	int i;
	char d, v;
	for(i=0; i<strlen(s)/2; i++){
		v = s[i];
		d = s[strlen(s)-i-1];
		if(v != d){
			add_char(s, strlen(s) - i, v);
			if(s[i+1] != d){
				add_char(s, i+1, d);
				i+=1;
			}
		}
	}
}
