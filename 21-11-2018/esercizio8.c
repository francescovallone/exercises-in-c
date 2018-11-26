#include <stdio.h>

int palindrome(char *v, int i);


int main(){
	char v[100];
	int i=0;
	scanf("%s", v);
	for(i=0; v[i] != '\0'; i++);
	printf("%d", palindrome(v, i));
	return 0;
}


int palindrome(char *v, int i){
	int l, n, flag=1;
	for(l=0; l <= i/2 && flag; l++){
		flag = v[l] == v[(i-1)-l] ? 1 : 0;
	}
	return flag;
}

