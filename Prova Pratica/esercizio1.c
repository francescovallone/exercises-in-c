#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node* next;
};

typedef struct node Node;
typedef Node* ptrNode;


void insert(ptrNode* head, int value){
	ptrNode temp = malloc(sizeof(Node));
	if(temp != NULL){
		temp->value = value;
		temp->next = (*head);
		(*head) = temp;
	}
}


void printList(ptrNode head){
	while(head != NULL){
		printf("%3d", head->value);
		head = head->next;
	}
}


void fold(ptrNode head, ptrNode* folded, int N, int M, int p){
	int** arrays = malloc(p*sizeof(int*));
	for(int r = 0; r<p; r++){
		arrays[r] = calloc(M, sizeof(int));
	}
	int i = 0, j = 0;
	while(head->next != NULL){
		arrays[i][j] = head->value;
		if(j == M-1){
			j = 0;
			i++;
		}else{
			j++;
		}
		head = head->next;
		if(head->next == NULL){
			arrays[i][j] = head->value;
			if(j < M - 1){
				arrays[i][M - 1] = -1;
			}
		}
	}
	int c;
	for(j = 0; j<M/2; j++){
		if(arrays[0][M-1] != -1){
			int c = arrays[0][j];
			arrays[0][j] = arrays[0][M-1-j];
			arrays[0][M-1-j] = c;
		}
	}
	for(i = 1; i<p; i++){
		for(j = 0; j<M; j++){
			if(arrays[i][M-1] != -1){
				arrays[0][j] += arrays[i][j];
			}
		}
	}
	if(arrays[p-1][M-1] == -1){
		for(j = 1; j<M-1; j++){
			arrays[p-1][0] += arrays[p-1][j];
		}
	}
	for(i = 0; i < M; i++){
		insert(folded, arrays[0][i]);
	}
	if(arrays[p-1][M-1] == -1){
		insert(folded, arrays[p-1][0]);
	}
}

void reverse(ptrNode* head){
    ptrNode prev = NULL; 
    ptrNode current = *head; 
    ptrNode next = NULL; 
    while (current != NULL) { 
        next  = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    } 
    *head = prev; 
}


int main(int argc, char *argv[]){
	ptrNode head = NULL;
	ptrNode head2 = NULL;
	int N = argc-1, M;
	for(int i = 1; i<argc; i++){
		insert(&head, atoi(argv[i]));
	}
	printList(head);
	printf("\n");
	scanf("%d", &M);
	getchar();
	while(M > N){
		printf("Please Enter a value between 1 and %d: ", N-1);
		scanf("%d", &M);
		getchar();
	}
	printf("\n");
	int p = N%M ? (N/M) + 1 : (N/M);
	fold(head, &head2, N, M, p);
	reverse(&head2);
	printList(head2);
	return 0;
}