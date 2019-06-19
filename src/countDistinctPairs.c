/*
Count all distinct pairs with difference equal to k
Given an integer array and a positive integer k, count all distinct pairs with difference equal to k.

Input: arr[] = {1, 5, 3, 4, 2}, k = 3
Output: 2
There are 2 pairs with difference 3, the pairs are {1, 4} and {5, 2} 

Input: arr[] = {8, 12, 16, 4, 0, 20}, k = 4
Output: 5
There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, {8, 12}, {12, 16} and {16, 20} 

*/


#include<stdio.h>
#include<stdlib.h>

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}//cmp

int countPairs(int *array,int size,int k){
    
    int low=0,high=0,count=0;
    
    while(high<size){
        int diff = array[high]-array[low];
        if(diff < k)
            high++;
        else if(diff > k)
            low++;
        else {// diff == k
            printf("\n%d\t%d",array[low],array[high]);
            count++;
            low++;
            high++;
        }
    }//while
    
    
    //brute force approach
    // for(int i=0;i<size-1;i++){
    //     for(int j=i+1;j<size;j++){
    //         if(abs(array[i]-array[j])==k)
    //             printf("%d\t%d\n",array[i],array[j]);
    //     }//for j
    // }//for i
    return count;
}//countPairs

int main() {
    // int array[]={8, 12, 16, 4, 0, 20},k=4;
    int array[]={1, 5, 3, 4, 2},k=3;
    int size = sizeof(array)/sizeof(array[0]);
    qsort(array,size,sizeof(int),cmp);
    
    // for(int i=0;i<size;i++)
    //     printf("%d\t",array[i]);
    
    printf("\nNumber of Pairs = %d\n",countPairs(array,size,k));
    return 0;
}

/*
Input :array= {8, 12, 16, 4, 0, 20}, k=4

Output : 
0	4
4	8
8	12
12	16
16	20
Number of Pairs = 5

Input :array= {1, 5, 3, 4, 2}, k=3

Output :
1	4
2	5
Number of Pairs = 2


*/
