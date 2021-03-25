/*
K’th Smallest/Largest Element in Unsorted Array | Set 2 (Expected Linear Time)
Difficulty Level : Hard
Last Updated : 17 Mar, 2021
We recommend reading the following post as a prerequisite of this post.

K’th Smallest/Largest Element in Unsorted Array | Set 1

Given an array and a number k where k is smaller than the size of the array, we need to find the k’th smallest element in the given array. It is given that all array elements are distinct.

Examples: 

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 4
Output: 10

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}//swap

void util(int *array, int n, int i){
    
    int l = 2*i+1, r = 2*i+2, root = i;
    while(i<n){
        if(l<n && array[l]<array[root])
            root=l;
        if(r<n && array[r]<array[root])
            root=r;
        if(root!=i){
            swap(&array[i], &array[root]);
            root = i;
        }//if
        else
            break;
    }//while
}//util

void minHeap(int *array, int n){
    if(n==0 || n==1)
        return;
    
    for(int i=0;i<=floor(n/2);i++)
        util(array, n, i);
    
    // for(int i=0;i<n;i++)
    //     printf("%d\t", array[i]);
    
}//minHeap

void extractHeap(int *array, int n, int k){
    if(k>n)
        return;
    
    for(int i=0;i<k;i++){
        if(i==k-1)
            printf("%d\t", array[0]);
        array[0] = array[--n];
        minHeap(array, n);
    }
}

int main() {
	//code
	int array[]={7, 10, 4, 3, 20, 15};
	int size = sizeof(array)/sizeof(array[0]);
	int k=4;
	minHeap(array, size);
	extractHeap(array, size, k);
	
	return 0;
}

/*
10
*/
