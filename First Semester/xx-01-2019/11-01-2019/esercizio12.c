#include <stdio.h>
#include <stdlib.h>

int* trova_max_parziale(int* A, int n){
    int *V = malloc((100)*sizeof(int)), k=0;
    for(int i=0; i<n; i++){
        /* Verifica che A[0] sia maggiore del suo successivo e in quel caso viene inserito in V */
        if(A[0] > A[1]){
            V[0] = A[0];
            /* Impongo i = 2 perché se A[0] è maggiore di A[1] allora A[1] non è massimo relativo */
            i = 2;
            k++;
        /* Verifica che A[n-1] sia maggiore del suo precedente e in quel caso lo inserisce in V */
        }else if(i == (n-1) && A[n-1] > A[n-2]){
            V[k] = A[i];
        /* Verifica che A[i] sia maggiore del suo precedente e minore del suo successivo */
        }else if(A[i] > A[i-1] && A[i] > A[i+1]){
            V[k] = A[i];
            k++;
        }
    }
    /* Ritorna il puntatore del vettore V */
    return V;
}

int main(){
    int A[11] = {11,22,33,44,5,66,7,88,99,10,202};
    int n = (int) sizeof(A)/sizeof(A[0]);
    int *V;
    V = trova_max_parziale(A, n);
    free(V);
    return 0;
}