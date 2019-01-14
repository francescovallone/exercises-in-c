#include <stdio.h>


int controlla_matrice(int *A, int n){
    /* Ammetto che siano tutti diversi ponendo la flag ad 1 */
    int flag = 1;
    /* La flag verrà usata come variabile del return e come controllo per il for */
    for(int i = 0, k=0; i<n && k<n && flag; i++){
        /* Se il valore di A in posizione i e di A in posizione i+1
            sono diversi allora continua il ciclo altrimenti esce dal ciclo*/
        if(k != i){
            if(A[k] != A[i]){
                flag = 1;
            }else{
                flag = 0;
            }
        }
        if(i<n){
            i = 0;
            k++;
        }
    }
    /* Alla fine la flag verrà ritornata sia che sia 1 sia che sia 0 */
    return flag;
}


int main(){
    int A[6] = {1,2,3,4,5,6}, n = 6;
    printf("%d", controlla_matrice(A, n));
    return 0;
}