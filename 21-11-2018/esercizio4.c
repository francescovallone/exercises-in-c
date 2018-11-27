#include <stdio.h>


int main(){
	char v[100];
	int i,l;
	scanf("%[^\n]s", v);
	for(i=0; v[i] != '\0'; i++);
	for(l=0; l < i; l++){
		if(v[l] >= 'a' && v[l] <= 'z' && v[l] != ' '){
			v[l] = (int) v[l] - 32;
		}
	}
	printf("%s", v);
	return 0;
}
