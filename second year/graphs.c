#include<stdio.h>
#define tepe_sayisi 6 // tepe say�s�n�n 6 oldu�u varsay�l�yor
struct vertex {
	int node;
	struct vertex *nextVertex;
};

struct vertex *head[tepe_sayisi]; // 6 boyutlu, bir ba�l� liste ba��

/* Y�nl� bir grafta giri� derecesini veren fonksiyon */
int indegree(int a[][tepe_sayisi], int v) {
	int i, degree = 0;
	for(i = 0; i < tepe_sayisi; i++)
		degree += a[i][v]; // v s�tunundaki 1'ler toplan�yor
	return degree; // giri� derecesi (indegree) geri d�nd�r�l�yor
}

/* Y�nl� bir grafta ��k�� derecesini veren fonksiyon */
int outdegree(int a[][tepe_sayisi], int v) {
	int i, degree = 0;
	for(i = 0; i < tepe_sayisi; i++)
		degree += a[v][i]; // v sat�r�ndaki 1'ler toplan�yor
	return degree; // ��k�� derecesi (outdegree) geri d�nd�r�l�yor
}

int outdegree(struct node heads[], int v) {
	struct node *temp=head[v];
	int degree = 0;
	while(temp!=NULL){
		degree++;
		temp=temp->next;
	}
	return degree-1;
}

//return degree in an undirected graph is represented by adjacency matrix
int degree(int a[][tepe_sayisi], int v, int n){
    int degree = 0, i;
    for ( i = 0; i < n; i++)
        degree += a[v][i];
    return degree;
}

//return indegree in a digraph is represented by adjacency matrix
int degree(int a[][tepe_sayisi], int v, int n){
    int degree = 0, i;
    for ( i = 0; i < n; i++)
        degree += a[i][v];
    return degree;
}

int edges(a[][], int n){
	int result=0,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		result[i][j];
	}
	return result/2;
}

int true_false_edges(struct node heads[], int v, int u) {
	struct node *temp=head[u];
	while(temp->next!=NULL){
		if(temp->next->data==v)
			return 1;
		temp=temp->next;
	}
	return 0;
}

main(){
	
}
