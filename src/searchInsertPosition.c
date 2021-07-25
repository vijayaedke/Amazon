/*
35. Search Insert Position
Easy
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if 
it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.


Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0
Example 5:

Input: nums = [1], target = 0
Output: 0
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

*/

int searchInsert(int* nums, int numsSize, int target){
    
    if(numsSize==0)
        return nums[0] < target ? 1 : 0;
    
    if(target > nums[numsSize-1])
        return numsSize;
    else if(target < nums[0])
        return 0;
    else{
        int prev=0, mid=0, start=0, end=numsSize;
        
        while(end>=start){
            mid = start + (end-start) / 2;
            
            if(target==nums[mid])
                return mid;
            if(target<nums[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        return start;
    }//else

}
/*
input : 
[1,3,5,6]
5
[1,3,5,6]
2
[1,3,5,6]
7
[1,3,5,6]
0
[1]
0
[1,3]
2


output:
2
1
4
0
0
1

*/
