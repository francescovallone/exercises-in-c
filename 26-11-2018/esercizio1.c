#include <stdio.h>
#include <string.h>


int compare(char *s, char *t);


int main(){
	char s[100] = "ciaociao";
	char t[100] = "cio"; // Stampare 2
	printf("%d \n", compare(s, t));
	return 0;
}


int compare(char *s, char *t){
	int k=0, i, j, r;
	for(i = 0, r = 0, j=0; i < strlen(s) && r < strlen(t); i++){
		if(s[i] == t[r]){
			j++;
			r++;
		}

		if(!(j%strlen(t))){
			k++;
			r = 0;
		}
	}
	
	return k;
}
