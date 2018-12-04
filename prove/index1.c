/* Esercizio suggerito da Marco */

#include <stdio.h>
#include <string.h>


int main(){
	char c, s[100]="cciiao";
	int j, l;
	for (j = 0; j < strlen(s); j++){
		for (l = 0; l < strlen(s); l++){
			if (s[l] > s[j]){
				c = s[j];
				s[j] = s[l];
				s[l] = c;
			}  
		}
	}
	printf("%s", s);
	return 0;
}
