/**Pair with given product | Set 1 (Find if any pair exists)
Given an array of distinct elements and a number x, find if there is a pair with product equal to x.
**/

#include<stdio.h>
#include<stdlib.h>

int getProduct(int array[],int n,int prod){
    int high=n-1;
    int low =0;
    
    while(low<high){
        int product = array[low] * array[high];
        if(product==prod)
            return 1;
        if(product>prod)
            high--;
        else
            low--;
    }//while
    return 0;
}

int main(){
    int testcases;
    scanf("%d",&testcases);
    while(testcases--){
        int n,product;
        scanf("%d%d",&n,&product);
        int array[n];
        for(int i=0;i<n;i++)
            scanf("%d",&array[i]);
        printf("%d\n",getProduct(array,n,product));
    }
    
    return 0;
}


/*
inputs:

1
4 407
10 20 9 40
output : 
0

inputs:
1
4 400
-10 20 9 -40

output : 
1

*/
