/*
Given an array of integers where 1 \leq A[i] \leq 10^{18}. In one operation you can either Increment/Decrement any element by 1. The task is to find the minimum operations needed to be performed on the array elements to make all array elements equal.

Examples:

Input : A[] = { 1, 5, 7, 10 }
Output : 11
Increment 1 by 4, 5 by 0.
Decrement 7 by 2, 10 by 5.
New array A = { 5, 5, 5, 5 } with 
cost of operations = 4 + 0 + 2 + 5 = 11.

Input : A = { 10, 2, 20 }
Output : 18
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int cmp(const void* a, const void* b){
    return ( *(int*)a - *(int *)b);
}

void findMinCostOperation(int *array, int n){
    if(array==NULL || n<=0)
        return;
    qsort(array, n, sizeof(int), cmp);
        
    int i=0, k=(int)n/2;
    
    if(n%2==0)
        k = (int)n/2<(int)(n/2)-1?(int)n/2:(int)n/2-1;
    
    int count=0, op=0;
    
    while(i<n){
        if(array[i]<array[k]){
            count = array[k] - array[i];
            op+=count;
            array[i] += count;
        }//if
        else if( array[i] > array[k] ){
            count = array[i] - array[k];
            op+=count;
            array[i] -= count;
        }//else
        
        i++;
    }//while
    
    for(int i=0;i<n;i++)
        printf("%d\t", array[i]);
        
    printf("\nOperation cost = %d", op);
    
}//findMinCostOperation

int main() {
   int array[] = {1, 6, 7, 10};
   findMinCostOperation(array, sizeof(array)/sizeof(int));
   
   return 0;
}

/*
input:
{1, 6, 7, 10}
output : 
6	6	6	6	
Operation cost = 10
*/
