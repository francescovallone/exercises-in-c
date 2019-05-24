#include "item.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


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
			(*ptr)->item = malloc((strlen(item)+1)*sizeof(char));
			strcpy((*ptr)->item, item);
			(*ptr)->right = NULL;
		}else{
			printf("Nope!");
		}
	}else{
		if(strcmp((*ptr)->item, item) > 0){
			insertNode(&(*ptr)->left, item);
		}else if(strcmp((*ptr)->item, item) < 0){
			insertNode(&(*ptr)->right, item);
		}else{
			printf("Duplicate");
		}
	}
}

void inOrder(TreePtr ptr){
	if(ptr != NULL){
		inOrder(ptr->left);
		printf("%s\n", ptr->item);
		inOrder(ptr->right);
	}
}

void preOrder(TreePtr ptr){
	if(ptr != NULL){
		printf("%s\n", ptr->item);
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

void postOrder(TreePtr ptr){
	if(ptr != NULL){
		postOrder(ptr->left);
		postOrder(ptr->right);
		printf("%s\n", ptr->item);
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
		if(strcmp(tempNode->item, item) == 0){
			return true;
		}else if(strcmp(tempNode->item, item) < 0){
			tempNode = tempNode->right;
		}else if(strcmp(tempNode->item, item) > 0){
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
    printf("%s\n", ptr->item); 
    printTree(ptr->left, space); 
} 
   
void print() { 
   printTree(root, 0);
   printf("\n== INORDER ==\n");
   treeInOrder();
   printf("\n== PREORDER ==\n");
   treePreOrder();
   printf("\n== POSTORDER ==\n");
   treePostOrder();
}

int distanceFromRoot(Item item, TreePtr ptr){
	if(strcmp(ptr->item, item) == 0) return 0;
	else if(strcmp(ptr->item, item) > 0) return distanceFromRoot(item, ptr->left);
	else return distanceFromRoot(item, ptr->right);
}

int distance(Item from, Item to, TreePtr ptr){
	if(ptr == NULL) return -1;
	if(strcmp(ptr->item, from) < 0 && strcmp(ptr->item, to) < 0){
		return distance(from, to, ptr->right);
	}
	if(strcmp(ptr->item, from) > 0 && strcmp(ptr->item, to) > 0){
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
		if(strcmp((*ptr)->item, item) > 0){
			delete(&((*ptr)->left), item);
			return;
		}else if(strcmp((*ptr)->item, item) < 0){
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