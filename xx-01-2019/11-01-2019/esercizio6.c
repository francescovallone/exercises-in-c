#include <stdio.h>
#include <stdlib.h>

int* somma_parziale(int* A, int n){
    int *p, *q;
    int *V = malloc((n/2)*sizeof(int)), i=0;
    p = A,  q = A+(n-2);
    /* Esegue il while se i è minore di n/2 */
    while(i<(n/2)){
        /* Verifica che il puntatore a p sia minore di q e in quel caso esegue la somma */
        if(p<q){
            V[i] = (*p+*q);
            p++; q--;
        /* Quando p e q sono uguali (caso di lunghezza dell'array dispari) impone V[i] a valore di A[i] */
        }else{
            V[i] = A[i];
        }
        i++;
    }
    return V;
}

int main(){
    int A[12] = {11,22,33,44,55,66,77,88,99,101,202};
    /* Essendo A un array e avendo dimensione N volte superiore a un suo elemento si può trovare
        la lunghezza dell'array facendo la divisione tra la dimensione in byte dell'array 
        e la dimensione in byte del primo elemento */
    int n = (int) sizeof(A)/sizeof(A[0]);
    int *V;
    V = somma_parziale(A, n);
    for(int i=0; i<(n/2); i++){
        printf("%d\t", V[i]);
    }
    free(V);
    return 0;
}