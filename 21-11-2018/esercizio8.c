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
	int l, n, flag=0;
	for(l=0, n=i-1; l<=n && n>=l; n--, l++){
		if(v[l] == v[n]){
			flag = 1;
		}else{
			return 0;
		}
	}
	if(flag) return 1;
}

