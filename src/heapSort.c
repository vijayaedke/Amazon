/*
Heap sort :
1. Iterative Approach
2. Recursive Approach

parent = 0
left = 2*0+1;
right = 2*0+2;

Generalized, form of heapify, the left node, right node and root node is denoted as follows :
parent = floor((i-1)/2)
left = 2*i+1
right = 2*i+2

Min heap 
Parent Node is Minimum element compared to its left and right node

Max heap
Parent node is Maximum element compared to its left and right node


Algorithm:
func heapify(array,size,index_node):
1. Initializa the parent node and index_node
2. while index_node < heap_size
  2.a parent = index_node
  2.b left = 2*index_node+1
  2.c right = 2*index_node+2
  2.d if array[left] < array[parent]
        then parent = left
  2.e if array[right] < array[parent]
        then parent = right
  2.f if parent!=index_node then
        swap(array[parent],array[index_node])
        recall recursively heapify(array,heap_size,parent)
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}//swap

void printArray(int array[],int size){
    for(int i=0;i<size;i++)
        printf("%d\t",array[i]);
}//printArray

void heapify(int array[],int size,int i){
    int largest=i;
    while(i<size){
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<size && array[largest]>array[left])
            largest=left;
        if(right<size && array[largest]>array[right])
            largest=right;
        
        if(largest!=i){
            swap(&array[largest],&array[i]);
            i=largest;
        }
        else
            break;
    }//while
    
}//heapify

void heapifyUtil(int array[],int size,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(array[largest]>array[left])
        largest=left;
    
    if(array[largest]>array[right])
        largest=right;
        
    if(largest!=i){
        swap(&array[largest],&array[i]);
        heapifyUtil(array,size,largest);
    }
}

void recursiveHeapify(int array[],int size){
    int largest=0;
    heapifyUtil(array,size,largest);
    
    printArray(array,size);
}

int main(){
    int array[] = {3,28,25,10,1,-56};
    int size = sizeof(array)/sizeof(array[0]);
    
    //iterative approach
    printf("\nIterative Approach\n");
    for(int i=floor(size/2);i>=0;i--)
        heapify(array,size,i);
    
    printArray(array,size);
    
    //recursive approach
    printf("\nRecursive Approach\n");
    recursiveHeapify(array,size);
    
    return 0;
}
