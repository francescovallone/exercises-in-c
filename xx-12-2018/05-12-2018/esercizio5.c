#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init_ab(char** v, char** z, int* n);
char* search(char** v, char** z, char* s, char* t, int n);
char** order(char** v, char** z, int n);
void print_string_vector(char *s, char **v, int dim);


int main(){
	char** v, z;
	v = (char**) malloc(200*sizeof(char*));
	z = (char**) malloc(200*sizeof(char*));
	char s[200], t[200];
	int* n;
	init_ab(v, z, &n);
	int r = n;
	printf("Inserisci il nome completo della persona che vuoi cercare: ");
	scanf("%[^\n]s", t);
	getchar();
	search(v, z, &s, t, r);
	printf("Il numero di %s è %s", t, s);
	free(v);
	free(z);
	return 0;
}


void init_ab(char** v, char** z, int* n){
	char s[200], t[200];
	int flag = 1, i;
	printf("Ora dovrai inserire il nome completo [nome e cognome] di ogni contatto, se vuoi smettere scrivi 'close'.\n");
	i=0;
	do{
		printf("Inserisci nome e cognome del contatto: ");
		scanf("%[^\n]s", s);
		getchar();
		if(!strcmp(s, "close")){
			flag = 0;
		}else{
			printf("Inserisci ora il numero di %s: ", s);
			scanf("%s", t);
			getchar();
			v[i] = (char*) malloc((strlen(s))*sizeof(char));
			z[i] = (char*) malloc((strlen(t))*sizeof(char));
			strcpy(v[i], s);
			strcpy(z[i], t);
			i++;
		}
	}while(flag);
	*n = i;
}


void print_string_vector(char *s, char **v, int dim){
	printf("%s", s);
	printf("{");
	for(int i=0; i < dim; i++){
		if(i != dim-1){
			printf("%s, ", v[i]);
		}else{
			printf("%s", v[i]);
		}
	}
	printf("}\n");
}


char** order(char** v, char** z, int n){
	int l, j;
	char* c, r;
	c = (char*) malloc(200*sizeof(char));
	r = (char*) malloc(200*sizeof(char));
	for (j = 0; j < n; j++){
		for (l = 0; l < n; l++){
			if (strcmp(v[l], v[j]) > 0){
				strcpy(c, v[j]);
				strcpy(r, z[j]);
				strcpy(v[j], v[l]);
				strcpy(z[j], z[l]);
				strcpy(v[l], c);
				strcpy(z[l], r);
			}
		}
	}
	print_string_vector("Test: ", v, n);
	free(c);
	return v;
}


char* search(char** v, char** z, char* s, char* t, int n){
	int f = 0, l = n-1, m = (f+l)/2;
	v = order(v, z, n);
	while(f <= l){
		if(!strcmp(v[m], t)){
			strcpy(s, z[m]);
			return s;
		}else if(strcmp(v[m], t) < 0){
			f = m + 1;
		}else{
			l = m - 1;
		}
		if(f>l){
			strcpy(s, "Non esiste questo contatto!");
			return s;
		}
		m = (f + l)/2;
	}
	return s;
}
