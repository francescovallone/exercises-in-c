#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /* Apro e leggo il file */
    FILE* f = fopen(argv[1], "r");
    /* Creo un array di stringhe e uno di caratteri */
    char** v = (char**) malloc(1*sizeof(char*));
    char* n = (char*) malloc(200*sizeof(char));
    int i, j, r;
    /* Prendo il valore di r (n nella consegna) */
    scanf("%d", &r);
    getchar();
    /* Se il file è nullo il programma si chiude */
    if(f == NULL){
        printf("Il file e' vuoto!");
        free(v);
        return 0;
    }
    /* Prende tutte le stringhe presenti nel file saltando gli spazi e rialloca la memoria per l'array di stringhe */
    for(i = 0; fscanf(f, "%s", n) != EOF; i++){
        v = (char**) realloc(v, (1+i)*sizeof(char*));
        v[i] = (char*) malloc(strlen(n)*sizeof(char));
        /* Copia la stringa in v[i] */
        strcpy(v[i], n);
    }
    /* Stampa tutte le stringhe da r a i */
    if(r <= i){
        for(j=r; j<i; j++){
            printf("%s\t", v[j]);
        }
    }
    free(v);
    fclose(f);
    return 0;
}