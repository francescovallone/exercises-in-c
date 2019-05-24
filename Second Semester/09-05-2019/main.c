#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "item.h"
#include <time.h>
#include "queue.h"
#include "itemqueue.h"


int main(){
	Item n, t;
	initTree();
	queueInit();
	srand(time(NULL));
	for(int i = 0; i<10; i++){
		treeInsertNode((rand() % 90));
	}
	print();
	scanf("%d %d", &n, &t);
	//printf("%d\n", search(n));
	printf("Distance = %3d", distance(n, t));
	print();
	return 0;
}