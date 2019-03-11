#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char t[2000], c, **v;
    v = malloc(100*sizeof(char*));
    int i,j=0;
    scanf("%[^\n]s", t);
    getchar();
    scanf("%c", &c);
    getchar();
    for(i=0; i<strlen(t); i++){
        /* Controlla se il carattere in i di t sia uguale al carattere scelto dall'utente */
        if(t[i]== c){
            /* Alloca la memoria per il vettore j */
            v[j] = malloc((i)*sizeof(char));
            /* Copia in v[j] la stringa t fino ad i+1 */
            strncpy(v[j], t, i+1);
            v[j][i+1] = '\0';
            /* Ricopia la stringa t partendo dall'iesimo carattere in t */
            strcpy(t, &t[i+1]);
            printf("%s\t", v[j]);
            j++;
            i = 0;
        }
    }
    free(v);
    return 0;
}