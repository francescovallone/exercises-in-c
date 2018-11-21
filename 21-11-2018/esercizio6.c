#include <stdio.h>


int main(){
	char v[100], s[100];
	int i,l,c;
	scanf("%s", v);
	for(i=0; v[i] != '\0'; i++);
	for(l=0, c=0; c<i; l++){
		s[l] = v[c];
		if((l%2)){
			c++;
		}
	}
	s[i*2] = '\0';
	printf("%s", s);
	return 0;
}
