#include<stdio.h>
#include<stdlib.h>

int main() {
   int array[]={1,3,6};
    
    int sum=0;
    int len=sizeof(array)/sizeof(array[0]);
   /*
   Naive approach 
   1. Iterate two loops
   2. Calculate the bit difference using right shift and bitwise AND with 1.
    2.q If the two numbers in pair differ, increment count.
   3. Add the count to sum.
   
    for(int i=0;i<len;i++){
        int count=0;
        for(int j=0;j<len;j++){
            if( ( (array[i] >> i) & 1) != ( array[j] >> i) & 1)
                count++;
        }//for j
        sum+=(count*2);
    }//for i
    printf("Sum=%d",sum);
   */
   
   /*
   Since , an integer is represent as unsigned 32 bit integer , count the bit difference among the pair and add it to sum.
  1. Run a loop from ‘0’ to ’31’ and right shift the bits of A and B by ‘i’ places, then check whether the bit at the ‘0th’ position is different.
  2. If the bit is different then increase the count.
  3. As the numbers are less than 2^31, we only have to run the loop ’32’ times i.e. from ‘0’ to ’31’.
  4. We can get the 1st bit if we bitwise AND the number by 1.
  5. There would be “n-count” numbers with i’th bit not set. So count of differences at i’th bit would be “count * (n-count) * 2”, 
  the reason for this formula is as every pair having one element which has set bit at i’th position and second element having unset bit at i’th
  position contributes exactly 1 to sum, therefore total permutation count will be count*(n-count) and multiply by 2 is due to one more repetition 
  of all this type of pair as per given condition for making pair 1<=i,j<=N..
  
 
   */
    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<len;j++){
            
            if( (array[j] >> i) & 1 ){
                count++;
            }//if
        }//for j
        sum+=(count*(len-count)*2);
    }//for i
    
    printf("Sum=%d",sum);
   
    return 0;
}

/*
output : = 
Sum=12
*/
