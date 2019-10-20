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