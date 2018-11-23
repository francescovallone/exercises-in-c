#include <stdio.h>
#include <math.h>

int str_to_int(char *v);

int main(){
	char v[100];
	printf("Stringa: ");
	scanf("%[^\n]s", v);
	printf("%d", str_to_int(v));
	return 0;
}

int str_to_int(char *v){
	int i, l, j=0, r=0;
	for(i=0; v[i] != '\0'; i++);
	for(l=0; l<i; l++){
		if(v[l] >= '1' && v[l] <= '9'){
			r = r + (v[l] - 48) * pow(10, (i-1)-l);		
		}
	}
	return r;
}