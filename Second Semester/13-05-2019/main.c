#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "item.h"
#include <time.h>
#include <string.h>


int main(){
	Item n = malloc(1000*sizeof(char));
	Item token;
	initTree();
	printf("\n== TEST ==\n");
	scanf("%[^\n]s", n);
	token = strtok(n, " ");
	printf("\n== TEST ==\n");
	while(token != NULL){
		treeInsertNode(token);
    	token = strtok(NULL, " ");
	}
	print();

	free(n);
	return 0;
}