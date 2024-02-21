#include<stdio.h>
#define tepe_sayisi 6 // tepe sayısının 6 olduğu varsayılıyor
struct vertex {
	int node;
	struct vertex *nextVertex;
};

struct vertex *head[tepe_sayisi]; // 6 boyutlu, bir bağlı liste başı

/* Yönlü bir grafta giriş derecesini veren fonksiyon */
int indegree(int a[][tepe_sayisi], int v) {
	int i, degree = 0;
	for(i = 0; i < tepe_sayisi; i++)
		degree += a[i][v]; // v sütunundaki 1'ler toplanıyor
	return degree; // giriş derecesi (indegree) geri döndürülüyor
}

/* Yönlü bir grafta çıkış derecesini veren fonksiyon */
int outdegree(int a[][tepe_sayisi], int v) {
	int i, degree = 0;
	for(i = 0; i < tepe_sayisi; i++)
		degree += a[v][i]; // v satırındaki 1'ler toplanıyor
	return degree; // çıkış derecesi (outdegree) geri döndürülüyor
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
