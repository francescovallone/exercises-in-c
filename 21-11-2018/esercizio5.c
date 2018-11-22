#include <stdio.h>


int main(){
	char v[100], s[100];
	int i;
	scanf("%[^\n]s", v);
	for(i=0; v[i] != '\0'; i++){
		s[i] = v[i];
	}
	s[i] == '\0';
	printf("%s", s);
	return 0;
}
