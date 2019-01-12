/*
Count pairs in a sorted array whose sum is less than x
Given a sorted integer array and number x, the task is to count pairs in array whose sum is less than x.

Input  : arr[] = {1, 3, 7, 9, 10, 11}
         x = 7
Output : 1
There is only one pair (1, 3)

Input  : arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
         x = 7
Output : 6
Pairs are (1, 2), (1, 3), (1, 4), (1, 5)
          (2, 3) and (2, 4)  
          
Solution : 
1. Initialize 2 variables low and high in an array and a counter variable to count pairs.
2. Traverse the array where
    while low < high:
        check sum = array[low] + array[high] < x
        if yes:
            increment count & low
        else
            decrement high
    end while loop
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int array[]={1, 2, 3, 4, 5, 6, 7, 8};
    int low=0,high=(sizeof(array)/sizeof(array[0]))-1;
    int x=7,count=0;
    while(low<high){
        int sum =array[low]+array[high];
        if(sum < x){
            count+=(high-low);
            low++;
        }
        else if(sum >=x){
            high--;
        }
    }//while
    
    printf("%d",count);
    return 0;
}


/*
Output :
 6
*/
