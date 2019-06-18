/*
Largest subset whose all elements are Fibonacci numbers
Given an array with positive number the task is that we find largest subset from array that contain elements which are Fibonacci numbers.

Input : arr[] = {1, 4, 3, 9, 10, 13, 7};
Output : subset[] = {1, 3, 13}
The output three numbers are Fibonacci
numbers.

Input  : arr[] = {0, 2, 8, 5, 2, 1, 4, 13, 23};
Output : subset[] = {0, 2, 8, 5, 2, 1, 13, 23}
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int getMax(int *array,int size){
    int max = array[0];
    for(int i=1;i<size;i++){
        if(max<array[i])
            max=array[i];
    }//for
    
    return max;
}//getMax

void storeFibInHashtable(int *hash,int max){
    int f1=0,f2=1;
    hash[f1]=f1;
    hash[f2]=f2;
    int sum=0;
    while(sum<=max){
        sum = f1+f2;
        hash[sum]=sum;
        f1=f2;
        f2=sum;
    }//for
}//storeFibInHashtable
     

void findLargestFibonacci(int *array,int size){
    int max = getMax(array,size);
    int hash[MAX]={0};
    storeFibInHashtable(hash,max+1);
    
    for(int i=0;i<size;i++){
        if(hash[array[i]]==array[i])
            printf("%d\t",array[i]);
    }//for
}//findLargestFibonacci

int main() {
    
    int array[]={1, 4, 3, 9, 10, 13, 7};
    int size = sizeof(array)/sizeof(array[0]);
    
    findLargestFibonacci(array,size);
    
    return 0;
}

/*

input : 1, 4, 3, 9, 10, 13, 7

output : 1	3	13	
--------------------------------------------------

input : 0, 2, 8, 5, 2, 1, 4, 13, 23

output : 0	2	8	5	2	1	13	
*/
