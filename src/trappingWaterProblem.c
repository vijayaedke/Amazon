/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
       | 
   |   || |
_|_||_||||||
Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2 

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void findMaxLeft(int *array,int n, int *left){
    int max=INT_MIN;
    
    for(int i=0;i<n;i++){
        if(max<array[i]){
            max=array[i];
        }
        left[i]=max;
    }//for
}//findMaxLeft

void findMaxRight(int *array, int n,int *right){
    int max=INT_MIN;
    
    for(int j=n-1;j>=0;j--){
        if(max<array[j]){
            max=array[j];
        }//if
        right[j]=max;
    }//for
}//findMaxRight

void printArray(int *array, int n){
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d\t", array[i]);
}//printArray

int min(int a, int b){
    return a<b?a:b;
}//min

int findWaterTrapped(int *array, int n){
    if(n==0 || array==NULL)
        return 0;
        
    if(n==1)
        return array[0];
    
    int *left = (int *)malloc(sizeof(int)*n);
    int *right = (int *)malloc(sizeof(int)*n);
    
    
    findMaxLeft(array, n, left);
    // printArray(left, n);
    findMaxRight(array, n, right);
    // printArray(right, n);
    
    int height=0;
    for(int i=0;i<n;i++){
        height+= (min(left[i], right[i]) - array[i]);
    }//for
    
    return height;
}//findWaterTrapped

int main() {
	//code
    int array[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size=sizeof(array) / sizeof(array[0]);
    printf("Water trapped = %d",findWaterTrapped(array, size));
	return 0;
}

/*
output : Water trapped = 6

*/
