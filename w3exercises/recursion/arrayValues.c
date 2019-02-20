#include <stdio.h>


int value(int n, int start, int* a);


int main(){
	int a[9] = {2,4,6,8,10,12,14,16,18};
	int n;
	scanf("%d", &n);
	value(n, 0, a);
	return 0;
}


int value(int n, int start, int* a){
	if(start >= n){
		return;
	}
	printf("%d ", a[start]);
	value(n, start+1, a);
}