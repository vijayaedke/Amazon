
/*
Median of two sorted arrays with different sizes in O(log(min(n, m)))
Given two sorted arrays, a[] and b[], task is to find the median of these sorted arrays, in O(log(min(n, m)), 
when n is the number of elements in the first array, and m is the number of elements in the second array.
Input : ar1[] = {-5, 3, 6, 12, 15}
        ar2[] = {-12, -10, -6, -3, 4, 10}
        The merged array is :
        ar3[] = {-12, -10, -6, -5 , -3,
                 3, 4, 6, 10, 12, 15}
Output : The median is 3.

Input : ar1[] = {2, 3, 5, 8}
        ar2[] = {10, 12, 14, 16, 18, 20}
        The merged array is :
        ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
        if the number of the elements are even, 
        so there are two middle elements,
        take the average between the two :
        (10 + 12) / 2 = 11.      
Output : The median is 11.
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double findMedian(int *array1,int size1,int *array2,int size2){
     int *res=(int *)malloc(sizeof(int)*(size1+size2));
    double median=0.0;
    int i=0,j=0,index=0;
    
    //check the size of both the array and calculate the median w.r.t first element
    if(size1==1 && size2==1)
        return (double)(array1[0]+array2[0])/2;
    
    //loop around both the arrays and compare the elements to merge the 2 two sorted arrays
    while(i<size1 && j<size2){
        if(array1[i]<=array2[j]){
            res[index]=array1[i];
            i++;
        }//if
        else if(array1[i]>array2[j]){
            res[index]=array2[j];
            j++;
        }//else if
        index++;
    }//while
    
    //add the remaining elements of array1
    while(i<size1){
        res[index++]=array1[i++];
    }//while
    
    //add the remaining elements of array2
    while(j<size2){
        res[index++]=array2[j++];
    }//while
    
    //print the merged array
    // for(int i=0;i<index;i++){
    //     printf("%d\t",res[i]);
    // }
    
    int medsize=size1+size2;
    if(medsize%2 == 0){
        printf("\nmedian = %d , median+1 = %d",res[(medsize/2)-1],res[medsize/2]);
        median=(double)(res[medsize/2]+res[(medsize/2)-1])/2;
    }
    else
        median=(double)res[medsize/2];
        
    return median; 
}//findMedian

int main() {
    int array1[]={-5, 3, 6, 12, 15};
    int array2[]={-12, -10, -6, -3, 4, 10};
//   int array1[]={2, 3, 5, 8};
//   int array2[]={10, 12, 14, 16, 18, 20};
//   int array1[]={1,2};
//   int array2[]={3,4};
//   int array1[]={1,1};
//   int array2[]={1,1};
//   int array1[]={1};
//   int array2[]={1};
   int size1=sizeof(array1)/sizeof(array1[0]);
   int size2=sizeof(array2)/sizeof(array2[0]);
   
   printf("\nMedian  = %lf",findMedian(array1,size1,array2,size2));
   return 0;
}

/*
Input : 
 array1[]={-5, 3, 6, 12, 15};
 array2[]={-12, -10, -6, -3, 4, 10};

Output : 
Median  = 3.000000

*/
