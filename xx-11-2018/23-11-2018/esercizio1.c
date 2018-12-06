#include <stdio.h>

int string_compare(char *v, char *s);

int main(){
	char v[100], s[100];
	printf("Prima Stringa: ");
	scanf("%[^\n]s", v);
	getchar();
	printf("Seconda Stringa: ");
	scanf("%[^\n]s", s);
	printf("%d", string_compare(v, s));
	return 0;
}

int string_compare(char *v, char *s){
	int i, l, j;
	for(i=0; v[i] != '\0'; i++);
	for(j=0; s[j] != '\0'; j++);
	
	for(l=0; l<j && l<i; l++){
		if(v[l] > s[l]){
			return -1;
		}else if(v[l] < s[l]){
			return 1;
		}
	}
	return 0;
}