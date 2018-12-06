#include <stdio.h>

int n_of_char(char *v, char c);

int main(){
	char v[100], c;
	printf("Stringa: ");
	scanf("%[^\n]s", v);
	getchar();
	printf("Scrivi la lettera: ");
	scanf("%c", &c);
	printf("%d", n_of_char(v,c));
	return 0;
}

int n_of_char(char *v, char c){
	int i, l, j=0;
	for(i=0; v[i] != '\0'; i++);
	for(l=0; l<i; l++){
		if(v[l] == c){
			j++;
		}
	}
	return j;
}