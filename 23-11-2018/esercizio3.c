#include <stdio.h>

void capitalize(char *v, char *s);

int main(){
	char v[100], s[100];
	printf("Stringa: ");
	scanf("%[^\n]s", v);
	capitalize(v, s);
	printf("%s", s);
	return 0;
}

void capitalize(char *v, char *s){
	int i, l, j=0, t=0, r;
	for(i=0; v[i] != '\0'; i++);
	for(l=0; l<i&&!(t); l++){
		if(v[l] == '.'){
			j = l+1;
			t = 1;
		}
		s[l] = v[l];
	}
	for(; j<i; j++){
		s[j] = (v[j] >= 'a' && v[j] <= 'z') ? v[j] - 32 : v[j];
	}
}