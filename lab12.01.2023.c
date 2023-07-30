#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

int degree(int A[][5], int v, int n){
	int result=0,i;
	for(i=0; i<n; i++)
		result+=A[v][i];
	return result;
}



int edges(int A[][5]){
	int i,j,result=0;
	for(i=0;i<5;i++)
		for(j=i+1;j<5;j++)
			result+=A[i][j];
	return result;
}

int main() {
	int n=5,i;
	int A[5][5]={{0,1,1,1,0},
				 {1,0,0,1,0},
				 {1,0,0,1,1},
				 {1,1,1,0,1},
				 {0,0,1,1,0}};
	int degreeSum=0;
	for(i=0;i<n;i++){
		degreeSum+=degree(A,i,n);
		printf("\nThe degree ofvertex %d=%d",i+1,degree(A,i,n));
	}
	printf("\nThe number of edges %d",edges(A));
	printf("\nSum of degrees = %d",degreeSum);
	return 0;
}
