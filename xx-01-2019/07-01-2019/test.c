#include <stdio.h>

int main(){
int
V[8]
={1,8,
2,
7,
3,
6,
5,4};
int
*p,
*q,a;
p
=
&V[5];q
=
&V[1];
a=
*(V+7+(q
-
p))+(*(p
-
2));
printf("%d", a);
}