#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void insertToMax_heap(int *array, int x, int index) {
	if(index == SIZE)
		printf("Heap dolu !\n");
	else {
		array[index] = x;
		while(index != 1 && array[index / 2] < array[index]) {
			swap(&array[index / 2], &array[index]); // yer de�i�tiriliyor
			index /= 2;
		}
	}
}

void insertToMin_heap(int *array, int x, int index) {
	if(index == SIZE)
		printf("Heap dolu !\n");
	else {
		array[index] = x;
		while(index != 1 && array[index / 2] > array[index]) {
			swap(&array[index / 2], &array[index]); // yer de�i�tiriliyor
			index /= 2;
		}
	}
}

int deleteMax(int *array, int queue_size) {
	int max, i = 1;
	if(queue_size == 1) {
		printf("Heap bos...\n");
		return 0;
	} else {
	max = array[i];
	array[i] = array[queue_size-1]; // son eleman ba�a atanarak max eleman siliniyor
	array[queue_size-1] = 0; // heap�in en ba�a atanan son eleman� siliniyor
	while(array[i] < array[2*i] || array[i] < array[(2*i) + 1]) {
		if(array[2*i] > array[(2*i) + 1]) { // sol �ocuk b�y�kse
			swap(&array[2*i], &array[i]); // sol �ocukla yer de�i�tiriliyor
			i = 2*i;
		}
		else { // sa� �ocuk b�y�kse
			swap(&array[(2*i) + 1], &array[i]); // sa� �ocukla yer de�i�tiriliyor
			i = (2*i) + 1;
		}z
	}
	return max;
	}
}

int main(){
	int array[SIZE],i;
//	FOR MAX
//	insertToMax_heap(&array,NULL,0);
	insertToMax_heap(&array,1,1);
	insertToMax_heap(&array,1,2);
	insertToMax_heap(&array,3,3);
	insertToMax_heap(&array,4,4);
	insertToMax_heap(&array,5,5);
	insertToMax_heap(&array,6,6);
	insertToMax_heap(&array,7,7);
	insertToMax_heap(&array,8,8);
	insertToMax_heap(&array,9,9);
	for(i=1;i<SIZE;i++)
		printf("%d\t",array[i]);
	printf("\n");
	
//	FOR MAX DELETE
	deleteMax(&array,10);
	for(i=1;i<SIZE;i++)
		printf("%d\t",array[i]);
	printf("\n");
	
//	FOR MIN
//	insertToMin_heap(&array,NULL,0);
	insertToMin_heap(&array,1,1);
	insertToMin_heap(&array,1,2);
	insertToMin_heap(&array,3,3);
	insertToMin_heap(&array,4,4);
	insertToMin_heap(&array,5,5);
	insertToMin_heap(&array,6,6);
	insertToMin_heap(&array,7,7);
	insertToMin_heap(&array,8,8);
	insertToMin_heap(&array,9,9);
	for(i=1;i<SIZE;i++)
		printf("%d\t",array[i]);
	return 0;
}
