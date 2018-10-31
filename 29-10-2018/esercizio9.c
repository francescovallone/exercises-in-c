#include <stdio.h>
#include <math.h>

int main(){
	int a, b, n, c;
	scanf("%d", &n);
	for(a = 1; a < n; a++) { 
        for (b = a+1; b < n; b++) {
			c = sqrt((a*a)+(b*b));
			if((c*c) == (a*a)+(b*b)){
				printf("%d %d %d\n", a, b, c); 
			}
        } 
    } 
    return 0;
}
