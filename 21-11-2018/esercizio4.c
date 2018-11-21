#include <stdio.h>


int main(){
	char v[100], s[100];
	int i,l,c;
	scanf("%s", v);
	for(i=0; v[i] != '\0'; i++);
	for(l=0; l < i; l++){
		if(v[l] >= 'a' && v[l] <= 'z'){
			c = (int) v[l] - 32;
			s[l] = c;		
		}
	}
	printf("%s \n", s);
	return 0;
}
