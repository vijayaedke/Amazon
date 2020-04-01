/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

#include <stdio.h>
#include <stdlib.h>

int maxArea(int* array, int heightSize){
    int l=0, r=heightSize-1, maxarea=0, i=0;
    
    while(l<r){
        int min = array[l]<array[r] ? array[l] : array[r];
        int cal = heightSize -1 - i;
        if(maxarea < (min * cal))
            maxarea = min * cal;
        
        if(array[l]<array[r])
            l++;
        else
            r--;
        i++;
    }//while
    
    return maxarea;
}



int main() {
	//code
	int array[]={1,8,6,2,5,4,8,3,7};
	int size = sizeof(array)/sizeof(array[0]);
	
	printf("\n%d", maxArea(array, size));
	
	return 0;
}

/*output:
49
*/
