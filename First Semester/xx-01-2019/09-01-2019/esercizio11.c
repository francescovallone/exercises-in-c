#include <stdio.h>


void separa(int *v, int l, int *pari, int *dispari){
    int j=0, k=0;
    for(int i=0; i<l; i++){
        if(v[i]%2 == 0){
            pari[j] = v[i];
            j++;
        }else{
            dispari[k] = v[i];
            k++;
        }
    }
}

int main(){
    int v[9] = {1,2,3,4,5,6,7,8,9}, l = 9;
    int pari[4];
    int dispari[5];
    separa(v, l, pari, dispari);
    printf("I numeri pari sono: ");
    for(int i=0; i<4; i++){
        printf("%d, ", pari[i]);
    }
    printf("\nI numeri dispari sono: ");
    for(int i=0; i<5; i++){
        printf("%d, ", dispari[i]);
    }
    return 0;
}