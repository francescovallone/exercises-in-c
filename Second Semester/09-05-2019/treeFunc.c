#include "item.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct treeNode{
	struct treeNode* left;
	Item item;
	struct treeNode* right;
};

typedef struct treeNode TreeNode;
typedef TreeNode* TreePtr;

static TreePtr root;

static void insertNode(TreePtr*, Item);
static void delete(TreePtr*, Item);
static TreePtr min(TreePtr);

void initTree(){
	root = NULL;
}


int treeIsEmpty(){
	return root == NULL;
}


void treeInsertNode(Item item){
	insertNode(&root, item);
}

static TreePtr min(TreePtr ptr){
	if(ptr->left == NULL) return ptr;
	else return min(ptr->left);
}

static void insertNode(TreePtr* ptr, Item item){
	if((*ptr) == NULL){
		(*ptr) = malloc(sizeof(TreeNode));
		if((*ptr) != NULL){
			(*ptr)->left = NULL;
			(*ptr)->item = item;
			(*ptr)->right = NULL;
		}else{
			printf("Nope!");
		}
	}else{
		if(item < (*ptr)->item){
			insertNode(&(*ptr)->left, item);
		}else if(item > (*ptr)->item){
			insertNode(&(*ptr)->right, item);
		}else{
			printf("Duplicate");
		}
	}
}

void inOrder(TreePtr ptr){
	if(ptr != NULL){
		inOrder(ptr->left);
		printf("%3d", root->item);
		inOrder(ptr->right);
	}
}

void preOrder(TreePtr ptr){
	if(ptr != NULL){
		printf("%3d", root->item);
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

void postOrder(TreePtr ptr){
	if(ptr != NULL){
		postOrder(ptr->left);
		postOrder(ptr->right);
		printf("%3d", root->item);
	}
}


void treeInOrder(void){
	if(!treeIsEmpty()){
		inOrder(root);
	}
}

void treePreOrder(void){
	if(!treeIsEmpty()){
		preOrder(root);
	}
}

void treePostOrder(void){
	if(!treeIsEmpty()){
		postOrder(root);
	}
}

bool search(Item item){
	TreePtr tempNode = root;
	while(tempNode){
		if(tempNode->item == item){
			return true;
		}else if(tempNode->item < item){
			tempNode = tempNode->right;
		}else if(tempNode->item > item){
			tempNode = tempNode->left;
		}
	}
	return false;
}


void printTree(TreePtr ptr, int space) 
{ 
    if (ptr == NULL) 
        return; 
    space += 5; 
    printTree(ptr->right, space); 
    printf("\n"); 
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%3d\n", ptr->item); 
    printTree(ptr->left, space); 
} 
   
void print() { 
   printTree(root, 0);
}

int distanceFromRoot(Item item, TreePtr ptr){
	if(item == ptr->item) return 0;
	else if(item < ptr->item) return distanceFromRoot(item, ptr->left);
	else return distanceFromRoot(item, ptr->right);
}

int distance(Item from, Item to, TreePtr ptr){
	if(ptr == NULL) return -1;
	if(from > ptr->item && to > ptr->item){
		return distance(from, to, ptr->right);
	}
	if(from < ptr->item && to < ptr->item){
		return distance(from, to, ptr->left);
	}
	return (distanceFromRoot(from, ptr) + distanceFromRoot(to, ptr));
}

int treeDistance(Item from, Item to){
	if(!search(from) || !search(to) || treeIsEmpty()) return -1;
	else return distance(from, to, root);
}

void deleteMin(TreePtr* ptr){
	if((*ptr)->left == NULL) {
		TreePtr temp = (*ptr)->right;
		free((*ptr));
		(*ptr) = temp;
	}else{
		deleteMin(&((*ptr)->left));
	}
}

void treeDeleteMin(){
	deleteMin(&root);
}

static void delete(TreePtr* ptr, Item item){
	if((*ptr) == NULL) return;
	else{
		if((*ptr)->item > item){
			delete(&((*ptr)->left), item);
			return;
		}else if((*ptr)->item < item){
			delete(&((*ptr)->right), item);
			return;
		}else{
			if((*ptr)->right == NULL){
				TreePtr temp = (*ptr)->left;
				free((*ptr));
				(*ptr) = temp;
				return;
			}
			(*ptr)->item = (min((*ptr)->right))->item;
			deleteMin(&((*ptr)->right));
		}
	}
}

void treeDelete(Item item){
	delete(&root, item);
}