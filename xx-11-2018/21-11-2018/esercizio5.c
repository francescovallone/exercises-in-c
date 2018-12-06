#include <stdio.h>


int main(){
	char v[100], s[100];
	int i;
	scanf("%[^\n]s", v);
	for(i=0; v[i] != '\0'; i++){
		s[i] = v[i];
	}
	printf("%s", s);
	return 0;
}
