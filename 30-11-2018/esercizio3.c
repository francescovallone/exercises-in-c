#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** console(char **v, int dim);
char** init_vector(char **v, int dim);
char** add_string(char **v, int dim);
void max_string(char **v, int dim);
void min_string(char **v, int dim);
char** del_string(char **v, int dim);
void search(char **v, int dim);
void get_index(char **v, int dim);
void print_int_vector(char *s, int v[],int dim);
void print_string_vector(char *s, char **v, int dim);


int main(){
	int size, n;
	printf("Inserisci la dimensione dell'array: ");
	scanf("%d", &size);
	getchar();
	char **v;
	v = (char**) malloc(size*sizeof(char*));
	v = init_vector(v, size);
	v = console(v, size);
	n = (int) sizeof(v)/sizeof(v[0]);
	for(int i=0; i<n; i++){
		free(v[i]);
	}
	free(v);
	return 0;
}


char** init_vector(char **v, int dim){
	int i;
	char input[1000];
	for(i=0; i<dim; i++){
		printf("Inserisci la stringa in posizione %d: ", i);
		scanf("%[^\n]s", input);
		getchar();
		v[i] = (char*) malloc((strlen(input))*sizeof(char));
		strcpy(v[i], input);
	}
	return v;
}


char** add_string(char **v, int dim){
	v = (char**) realloc(v, (dim)*sizeof(char*));
	char input[1000];
	printf("Inserisci la stringa che vuoi aggiungere: ");
	scanf("%[^\n]s", input);
	getchar();
	v[dim-1] = (char*) malloc((strlen(input))*sizeof(char));
	strcpy(v[dim-1], input);
	return v;
}


void max_string(char **v, int dim){
	char *max = v[0];
	for(int i=0; i<dim; i++){
		if(strcmp(max, v[i]) < 0){
			max = v[i];
		}
	}
	printf("La stringa piu' grande e' %s \n", max);
}


void min_string(char **v, int dim){
	char *min = v[0];
	for(int i=0; i<dim; i++){
		if(strcmp(min, v[i]) > 0){
			min = v[i];
		}
	}
	printf("La stringa piu' piccola e' %s \n", min);
}


char** del_string(char **v, int dim){
	char s[1000];
	print_string_vector("Il tuo array: ", v, dim+1);
	printf("\nScegli una delle stringhe che trovi nell'array qui sopra per cancellarla: ");
	scanf("%s", s);
	getchar();
	int pos;
	for(int i=0; i<=dim; i++){
		if(strcmp(s, v[i]) == 0){
			pos = i;
		}
	}
	for(int c=pos; c<dim; c++){
		v[c] = v[c+1];
	}
	v = (char**) realloc(v, dim*sizeof(char*));
	free(v[dim+1]);
	return v;
}


void search(char **v, int dim){
	int *t;
	char s[1000];
	int c,i, flag=1;
	t = calloc(1, sizeof(int));
	printf("Digita una stringa per scoprire la sua posizione: ");
	scanf("%s", s);
	for(i=0, c=0; i<dim && flag; i++){
		if(!(strcmp(s, v[i]))){
			t[c] = i;
			flag = 1;
			c++;
			t = realloc(t, c+1*sizeof(int));
		}else if(c == 0 && i == dim-1){
			flag = 0;
		}
	}
	if(flag){
		print_int_vector("La stringa dell'array compare in queste posizioni: ", t, c);
	}else{
		printf("La stringa %s non esiste all'interno dell'array.\n", s);
	}
	free(t);
}


void get_index(char **v, int dim){
	int *t;
	char s[1000];
	int c,i,flag;
	t = calloc(1, sizeof(int));
	printf("Digita una parola: ");
	scanf("%s", s);
	for(i=0, c=0; i<dim && flag; i++){
		if(strstr(v[i], s)){
			t[c] = i;
			c++;
			flag = 1;
			t = realloc(t, c+1*sizeof(int));
		}
		if(c==0 && i==dim-1){
			flag = 0;
		}
	}
	if(flag){
		print_int_vector("La parola si trova nelle stringhe di posizione: ", t, c);
	}else{
		printf("La parola %s non è presente in alcun elemento dell'array.\n", s);
	}
	free(t);
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


void print_int_vector(char *s, int *v, int dim){
	printf("%s", s);
	printf("{");
	for(int i=0; i < dim; i++){
		if(i != dim-1){
			printf("%d, ", v[i]);
		}else{
			printf("%d", v[i]);
		}
	}
	printf("}\n");
}


char** console(char **v, int dim){
	int n=0, size = dim;
	do{
		printf("Inserisci un valore da [1 a 6]\n");
		printf("1) Aggiungi una stringa all'array.\n");
		printf("2) Trova la stringa di lunghezza maggiore nell'array. \n");
		printf("3) Trova la stringa di lunghezza minore nell'array.\n");
		printf("4) Cancellare una stringa dall'array.\n");
		printf("5) Ricercare una stringa dell'array.\n");
		printf("6) Trova gli indici delle stringhe che contengono la parola P all'interno dell'array.\n");
		scanf("%d", &n);
		getchar();
		switch (n){
			case 1:
				size += 1;
				v = add_string(v, size);
				print_string_vector("Il nuovo array e': ", v, size);
				break;
			case 2:
				max_string(v, size);
				break;
			case 3:
				min_string(v, size);
				break;
			case 4:
				size -= 1;
				v = del_string(v, size);
				print_string_vector("Il nuovo array e': ", v, size);
				break;
			case 5:
				search(v, size);
				break;
			case 6:
				get_index(v, size);
				break;
			}
		}while(n>= 1 && n<= 8);
	return v;
}
