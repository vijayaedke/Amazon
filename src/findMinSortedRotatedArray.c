/*
Find the minimum element in a sorted and rotated array
A sorted array is rotated at some unknown point, find the minimum element in it.

Following solution assumes that all elements are distinct.
Examples:

Input: {5, 6, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4}
Output: 1

Input: {2, 1}
Output: 1

*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(int *array, int index1, int index2){
    if(array[index1] <= array[index2])
        return index1;
    return index2;
}//cmp

int findMin(int *array, int n){
    if(array==NULL || n==0)
        return -1;
    
    if(n==1)
        return array[0];
    
    int start=0, end=n;
    int mid =(int) ((start+end)/2);
    int min=array[mid];
    
    printf("start = %d, mid = %d, end =%d\n", start, mid, end);
    
    while(start < end ){
        int left = cmp(array, start, mid-1);
        printf("\nleft array[%d] = %d", left, array[left]);
        int right = cmp(array, mid+1, end);
        printf("\nRight array[%d] = %d", right, array[right]);
        int move = cmp(array, left, right);
        printf("\nMove array[%d] = %d", move, array[move]);

        if(move > mid ){
            if(array[mid] < array[move]){
                min = array[mid];
                break;
            }
            else{
                min = array[move];
                start=mid;
                mid = (int) ((mid+n)/2);   
            }//else
        }//if
        else{
            if(array[mid] < array[move]){
                min = array[mid];
                break;
            }
            else{
                min = array[move];
                end = mid;
                mid = (int) mid / 2; 
            }//else
            
        }//else
        
    }//while
    
    return min;
}//findMin

int main() {
	//code
    // int array[] = {5,6,7,1,2,3,4};
    // int array[] = {1, 2, 3, 4};
    int array[] = { 4, 6, 8, 10, 34, 56, 78, 1, 3 };

    int n = sizeof(array) / sizeof(array[0]);
    
    printf("\nMin = %d", findMin(array, n-1));

	return 0;
}

