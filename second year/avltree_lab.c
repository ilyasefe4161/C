#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int height;
	struct node *left;
	struct node *right;
};

typedef struct node AVLTREE;

int maxValue(int x, int y){
	return x >= y ? x:y;
}

AVLTREE *new_node(int data){
	AVLTREE *newnode=(AVLTREE*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	newnode->height=0;
	return newnode;
}

AVLTREE *rightRotate(AVLTREE *z){
	AVLTREE *temp=z->left;
	z->left=temp->right;
	temp->right=z;
	z->height = (height(z->left), height(z->right))+1;
	temp->height=maxValue(height(temp->left), height(temp->right))+1;
	return temp;
}

AVLTREE *leftRotate(AVLTREE *z){
	AVLTREE *temp=z->right;
	z->right=temp->left;
	temp->left=z;
	z->height=maxValue(z->left==NULL?-1:z->left->height,z->left==NULL?-1:z->right->height)+1;
	temp->height=maxValue(z->left==NULL?-1:temp->left->height, z->left==NULL?-1:temp->right->height)+1;
	return temp;
}
AVLTREE *leftRightRotate(AVLTREE *z)
{
	z->left=leftRotate(z->left);
	return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z)
{
	z->right=rightRotate(z->right);
	return leftRotate(z);
}

int height(AVLTREE *root){
	if(root==NULL)
		return -1;
	else{
		int lheight,rheight;
		rheight=height(root->right);
		lheight=height(root->left);
		if(rheight>lheight)
			return rheight+1;
		else
			return lheight+1;
	}
}

AVLTREE *insertToAVL(int x, AVLTREE *tree) {
	if(tree!=NULL)
	{
		if(x<tree->data)
		 tree->left=insertToAVL(x, tree->left);
		else
		 tree->right=insertToAVL(x,  tree->right);

		tree->height=maxValue(height(tree->left), height(tree->right))+1;
		if((height(tree->left)-height(tree->right))>1 && x< tree->left->data)
		 return rightRotate(tree);

		if((height(tree->left)-height(tree->right))>1 && x> tree->left->data)
		 return leftRightRotate(tree);

		if((height(tree->left)-height(tree->right))< -1 && x> tree->right->data)
		 return leftRotate(tree);

		if((height(tree->left)-height(tree->right))< -1 && x< tree->right->data)
		 return rightLeftRotate(tree);
	}
	else
	  tree=new_node(x);
	return tree;
}

void inorder(AVLTREE *root){
	printf("\n");
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
	printf("\n");
}

int main(){
	AVLTREE *agac=NULL;
	int key,secim;
	printf("Veri giriniz (Devam icin -1 girin.): ");
	scanf("%d",&key);
	while(key!=-1){
		agac=insertToAVL(key,agac);
		scanf("%d",&key);
	}
	do{
		printf("\n1-Insert\n2-Height\n3 Inorder\n4-Exit\nSeciminiz: ?");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				printf("\nVeri giriniz.\n");
				scanf("%d",&key);
				agac=insertToAVL(key,agac);
				printf("\nVeri Eklendi.\n");
				break;
			case 2:
				//printf("Height=%d",height(agac));
				printf("\nHeight=%d\n",agac->height);
				break;
			case 3:
				inorder(agac);
				break;
			case 4:
				exit(1);
			default:
				printf("\nHatali Secim...\n");
				break;
		}
	}while(1);
	return 0;
}
