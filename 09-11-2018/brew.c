#include <stdio.h>


int mcd(int a, int b){
	int m;
	if(a > b){
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	for(m=a; a%m || b%m; m--);
	return m;
}


int mcm(int a, int b){
	int m, t=1;
	if(a > b){
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	for(m=b; (m%a)||(m%b); m++);
	return m;
}


void analyze(void){
	int i=0, r, c=0, d=0, temp, pos=0, neg=0, even=0, odd=0, none=0;

	while(scanf("%d", &r)){
		if(i == 0){
			temp = r;
		}
		if(r < 0){
			neg++;
		}else if(r == 0){
			none++;
		}else{
			pos++;
		}
		if(r != 0 && !(r%2)){
			even++;
		}else if(r != 0){
			odd++;
		}
		if(r < temp){
			d++;
		}else if(r > temp){
			c++;
		}
		i++;
		temp = r;
	}
	if(d > 0 && c == 0){
		printf("La successione e' decrescente \n");
	}else if(c > 0 && d == 0){
		printf("La successione e' crescente \n");
	}else{
		printf("La successione non e' ne crescente ne decrescente \n");
	}
	printf("I numeri negativi sono %d \n", neg);
	printf("I numeri positivi sono %d \n", pos);
	printf("I numeri nulli sono %d \n", none);
	printf("I numeri pari sono %d \n", even);
	printf("I numeri dispari sono %d", odd);
}


void fibonacci(int a){
	int i, t=0, s=1, r=0;
	for(i=1; i<=a; i++){
		printf("%d \t", t);
		r = t + s;
		t = s;
		s = r;
	}
}
