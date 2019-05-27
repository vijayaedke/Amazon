#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NA -1

void shiftElements(int *m,int msize){
    int i=msize-1;
    for(int j=msize-1;j>=0;j--){
        if(m[j]!=NA){
            m[i]=m[j];
            i--;
        }//if
    }//for
}//shiftElements

void printArray(int *m,int msize){
    for(int i=0;i<msize;i++)
        printf("%d\t",m[i]);
}//printArray

void mergeArrays(int *m,int *n,int msize,int nsize){
    int x=0,i=msize-nsize-1,j=0;
    
    while( x < msize ){
        if(m[i]<=n[j]){
            m[x++]=m[i++];
        }//if
        else if(m[i]>n[j]){
            m[x++]=n[j++];
        }//else if
    }//while
    
}//mergeArrays

int main() {
    int m[]={2, 8, NA, NA, NA, 13, NA, 15, 20};
    int n[]={5, 7, 9, 25};
    
    int msize=sizeof(m)/sizeof(m[0]);
    int nsize=sizeof(n)/sizeof(n[0]);
    
    shiftElements(m,msize);
    mergeArrays(m,n,msize,nsize);
    printArray(m,msize);
    
    return 0;
}
/*
output :
2	5	7	8	9	13	15	20	25	

*/
