/*
Find median in row wise sorted matrix
Difficulty Level : Hard
Last Updated : 30 Oct, 2020
We are given a row-wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.
Examples: 
Input : 1 3 5
        2 6 9
        3 6 9
Output : Median is 5
If we put all the values in a sorted 
array A[] = 1 2 3 3 5 6 6 9 9)
Input: 1 3 4
       2 5 6
       7 8 9
Output: Median is 5
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3
#include <limits.h>

int max(int a, int b){
    return a>b?a:b;
}//max

int min(int a, int b){
    return a<b?a:b;
}//min

int upperBound(int m[MAX], int mid){
    // int array[MAX*MAX] = {0};
    int low =0, high=MAX;
    
    while(low<high){
        int mid = high+(high-low)/2;
        
        if(mid>m[mid])
            low = mid+1;
        else
            high = mid;
    }//while
    
    return low;
}//upperBound

int findMedian(int m[][MAX]){
    int min_ = INT_MAX, max_ = INT_MIN;
    
    for(int i=0; i<MAX; i++){
        min_ = min(m[i][0], min_);
        max_ = max(m[i][MAX-1], max_);
    }//for
    
    int low=0, high=MAX;
    
    while(low<high){
        int mid = high+(high-low)/2;
        int count=0;
        for(int i=0;i<MAX;i++)
            count += upperBound(m[i],mid);
        
        if(count<mid)
            high = mid;
        else
            low = mid+1;
    }//while
    
    return low;
}//findMedian

int main() {
	int m[][MAX]= 
    { 
        {1,3,4}, 
        {2,5,6}, 
        {7,8,9} 
    };
    printf("%d\t", findMedian(m));
	return 0;
}

/*output:
5	
*/
