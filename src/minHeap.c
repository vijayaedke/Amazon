/*
Binary Heap
Last Updated: 04-09-2018
A Binary Heap is a Binary Tree with following properties.
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left
as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in
Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

Examples of Min Heap:

           10                     10
         /    \               /      \  
       20     100            15       30  
      /                      /  \     /  \
    30                     40    50 100   40

How is Binary Heap represented?
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an array.

The root element will be at Arr[0].
Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:
Arr[(i-1)/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct heap{
    unsigned size;
    int *array;
};

struct heap *init(unsigned capacity){
    struct heap *h = (struct heap *)malloc(sizeof(struct heap));
    h->size = capacity;
    h->array = (int *)malloc(sizeof(int) * capacity);
    return h;
}//init

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}//swap

void insertKey(struct heap *h,int *index, int key){
    if(*index==h->size){
        printf("\nHeap overflow\n");
        return;
    }
    
    h->array[(*index)] = key;
    int temp_index=*index;
    
    while(temp_index >0 && h->array[(temp_index-1)/2] > h->array[temp_index]){
        swap(&h->array[(temp_index-1)/2], &h->array[temp_index]);
        temp_index = (temp_index-1)/2;
    }//while
    (*index)++;
}//insertKey

void printArray(struct heap *h){
    for(int i=0;i<h->size;i++)
        printf("%d\t", h->array[i]);
        
    printf("\n");
}//printArray

void deceaseKey(struct heap *h, int index, int new_val){
    h->array[index] = new_val;
    if(index==h->size)
        return;
        
    while(index > 0 && h->array[(index-1)/2] > h->array[index]){
        swap(&h->array[index], &h->array[(index-1)/2]);
        index = (index-1)/2;
    }//while
}//deceaseKey

void heapify(struct heap *h, int i){
    int root = i;
    int left = 2*root+1;
    int right = 2*root+2;
    if(h->array[root] > h->array[left])
        root = left;
    
    if(h->array[root] > h->array[right])
        root = right;
    
    if(root!=i){
        swap(&h->array[i], &h->array[root]);
        heapify(h, root);
    }//if
}//heapify

int extractMin(struct heap *h){
    if(h->size<=0)
        return h->array[0];
    
    int root = h->array[0];
    h->array[0] = h->array[h->size-1];
    h->size=h->size-1;
    
    heapify(h, 0);
    return root;
}//extractMin

void deleteKey(struct heap *h, int key){
    deceaseKey(h, key, INT_MIN);
    extractMin(h);
}//deleteKey

int main() {
    struct heap *h = init(11);
    int index=0;
	insertKey(h,&index, 3);
	insertKey(h,&index, 10);
	insertKey(h,&index, 11);
	insertKey(h,&index, 5);
	insertKey(h,&index, 15);
	insertKey(h,&index, 17);
	insertKey(h,&index, 13);
	insertKey(h,&index, 12);
	insertKey(h,&index, 11);
	insertKey(h,&index, 8);
	insertKey(h,&index, 21);

	printArray(h);
	
	//extractMin
    printf("%d\n", extractMin(h));
    
    printArray(h);
    
    //deceaseKey
    deceaseKey(h, 2, 1);
    
    printArray(h);

	return 0;
}

/*
output:

3	5	11	10	8	17	13	12	11	15	21	
3
5	8	11	10	15	17	13	12	11	21	
1	8	5	10	15	17	13	12	11	21	

*/
