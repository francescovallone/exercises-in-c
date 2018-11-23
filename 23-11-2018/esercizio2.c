#include <stdio.h>

int n_of_cap(char *v);

int main(){
	char v[100];
	printf("Stringa: ");
	scanf("%[^\n]s", v);
	printf("%d", n_of_cap(v));
	return 0;
}

int n_of_cap(char *v){
	int i, l, j=0;
	for(i=0; v[i] != '\0'; i++);
	for(l=0; l<i; l++){
		if(v[l] >= 'A' && v[l] <= 'Z'){
			j++;
		}
	}
	return j;
}