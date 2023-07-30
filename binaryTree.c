#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node BTREE;

BTREE *new_node(int data){
	BTREE *p=(BTREE*)malloc(sizeof(BTREE*));
	p->data=data;
	p->left=p->right=NULL;
	return p;
}

BTREE *copyOdd(BTREE *root, BTREE *root2){
	if(root != NULL){
		if(root -> data % 2 == 1)
		root2 = insert(root2, root -> data);
		root2 = copyOdd(root -> left, root2);
		root2 = copyOdd(root -> right, root2);
		}
	return root2;
}

BTREE *insert(BTREE *root, int data){
	if(root != NULL){
		if(data < root -> data)
			root -> left = insert(root -> left, data);
		else
			root -> right = insert(root -> right, data);
	}
	else
		root = new_node(data);
	return root;
}

void preorder(BTREE *root){
	if(root != NULL){
		printf("%3d ",root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}

void inorder(BTREE *root){
	if(root != NULL){
		inorder(root -> left);
		printf("%3d ",root -> data);
		inorder(root -> right);
	}
}

void postorder(BTREE *root){
	if(root != NULL){
		postorder(root -> left);
		postorder(root -> right);
		printf("%3d ",root -> data);
	}
}

void mirror(BTREE* root) {
	if(root == NULL)
		return;
	else {	
		BTREE* temp;
		mirror(root -> left);
		mirror(root -> right);
		temp = root -> left; // swap
		root -> left = root -> right;
		root -> right = temp;
	}
}

void mirror0(BTREE* root) { // mirror and mirror0 are same
	if(root == NULL)
		return;
	else {	
		BTREE* temp;
		temp = root -> left; // swap
		root -> left = root -> right;
		root -> right = temp;
		mirror(root -> left);
		mirror(root -> right);
	}
}

BTREE *delete_node(BTREE* root, int x){
	BTREE *p,*q;
	if (root==NULL)
		return ; // no tree
	if(root->data==x){ //find x in root
		if(root->left==root->right){
		free(root);
		return;
	}else{
		if(root->left==NULL){
			p=root->right;
			free(root);
			return p;
		}else if(root->right==NULL){
			p=root->left;
			free(root);
			return p;
		}else{
			p=q=root->right;
			while(p->left!=NULL)
				p=p->left;
			p->left=root->left;
			free(root);
			return q;
			}
		}
	}
	if(root->data<x){
		root->right = delete_node(root->right,x);
	}
	else
		root->left=delete_node(root->left,x);
	return root;
}


int main(){
	BTREE *myroot = NULL,*m1;
	int i=0;
	do{
		printf("\nEnter a number for add a number to binary tree\nNumber = ");
		scanf("%d",&i);
		if(i != -1)
			myroot = insert(myroot,i);
	}while(i != -1);
	preorder(myroot);
	printf("\n");
	inorder(myroot);
	printf("\n");
	postorder(myroot);
	printf("\n");
	
	mirror(myroot);
	printf("\n");
	preorder(myroot);
	printf("\n");
	inorder(myroot);
	printf("\n");
	postorder(myroot);
	printf("\n");
	
	mirror0(myroot);
	printf("\n");
	preorder(myroot);
	printf("\n");
	inorder(myroot);
	printf("\n");
	postorder(myroot);
	
	printf("\n");
	copyOdd(myroot,m1);
	inorder(m1);
	return 0;
}
