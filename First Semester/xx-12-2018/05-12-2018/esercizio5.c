#include <stdio.h>
#include <string.h>


void init_ab(char v[][200], char d[][200], int* n);
char* search(int n, char v[][200], char d[][200], char* s);
void order(char v[][200], char d[][200], int n);


int main(){
	char v[10][200], d[10][200];
	char t[200];
	int* n;
	init_ab(v, d, &n);
	int r = n;
	printf("Inserisci il nome completo della persona che vuoi cercare: ");
	scanf("%[^\n]s", t);
	getchar();
	printf("Il numero di %s e' %s.", t, search(n, v, d, t));
	return 0;
}


void init_ab(char v[][200], char d[][200], int* n){
	char s[200], t[200];
	int flag = 1, i;
	printf("Ora dovrai inserire il nome completo [nome e cognome] di ogni contatto, se vuoi smettere scrivi 'close'.\n");
	for(i = 0; flag;){
		printf("Inserisci nome e cognome del contatto: ");
		scanf("%[^\n]s", s);
		getchar();
		if(!strcmp(s, "close")){
			flag = 0;
		}else{
			printf("Inserisci il numero di %s: ", s);
			scanf("%s", t);
			getchar();
			strcpy(v[i], s);
			strcpy(d[i], t);
			i++;
		}
	}
	*n = i;
}


void order(char v[][200], char d[][200], int n){
	char c[200], r[200];
	for (int j = 0; j < n; j++){
		for (int l = 0; l < n; l++){
			if (strcmp(v[l], v[j]) > 0){
				strcpy(c, v[j]);
				strcpy(r, d[j]);
				strcpy(v[j], v[l]);
				strcpy(d[j], d[l]);
				strcpy(v[l], c);
				strcpy(d[l], r);
			}
		}
	}
}


char* search(int n, char v[][200], char d[][200], char* s){
	int f = 0, l = n-1, m = (f+l)/2;
	order(v, d, n);
	while(f <= l){
		if(!strcmp(v[m], s)){
			return d[m];
		}else if(strcmp(v[m], s) < 0){
			f = m + 1;
		}else{
			l = m - 1;
		}
		if(f>l){
			return "Il contatto non è in rubrica";
		}
		m = (f + l)/2;
	}
}
