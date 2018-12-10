#include <stdio.h>
#include <unistd.h>


int main(){
for (float i=0;i<=1000000000000;i+=1){
	usleep(20000/i);
	int n = (int) i;
   	printf("\rValue of X is: %d", n);
}
return 0;
}
