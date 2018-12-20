#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE* f = fopen(argv[1], "r");
    float* v = (float*) calloc(1, sizeof(float));
    float n;
    int i, j;
    if(f == NULL){
        printf("Il file e' vuoto!");
        free(v);
        return 0;
    }
    for(i = 0; fscanf(f, "%f", &n) != EOF; i++){
        v = (float*) realloc(v, (1+i)*sizeof(float));
        v[i] = n;
    }
    for(j=0; j<i; j++){
        printf("%3.3f\t", v[j]);
    }
    free(v);
    fclose(f);
    return 0;
}