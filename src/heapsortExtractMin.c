
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void print(int *array,int n){
	for(int i=0;i<n;i++){
		printf("%d\t",array[i]);
}//for
}//print

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}//swap

void heaputil(int *array,int n,int i){
	int root=i;
	while(i<n){
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && array[left] < array[root])
            root=left;
        if(right < n && array[right] < array[root])
            root=right;
        if(i != root){
        	swap(&array[i],&array[root]);
        	root=i;
        }
        else
            break;
	}
 
}//heaputil

void heapsort(int *array,int n){
// 	int root=0;
	for(int i=floor(n/2);i>=0;i--)
	    heaputil(array,n,i);
	
// 	print(array,n);
}//heapsort

void extractMin(int *array,int n){
    if(n==0)
        return;
    int min = array[0];
    array[0] = array[n-1];
    heapsort(array,n-1);
    
    printf("\nMin = %d\t",min);
}

int main(){
	int array[] = {64,25,12,22,11};
	int size = sizeof(array)/sizeof(array[0]);
	heapsort(array,size);
    for(int i=0;i<4;i++)
        extractMin(array,size-i);
	return 0;
}
/*
output : 

Min = 11	
Min = 12	
Min = 22	
Min = 25	

*/
