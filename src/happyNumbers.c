/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number 
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those 
numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long check(long long n){
    long long sq = 0;
    while(n){
       int rem = n%10;
       sq+=pow(rem,2);
       n/=10;
    }//n
    // printf("\nSquare = %lld", sq);
    return sq;
}//check


int isHappy(int n){
    long long sq = n;
    // printf("%lld", sq);
    
    while(sq > 9){
        sq = check(sq);
        if(sq==1)
            return 1;
    }//while
    if(sq==7)
        return 1;
    
    return 0;
}//isHappy

int main() {
	//code
	int num=19;
// 	int num=20;
//  int num=1111111;
	if(isHappy(num))
	    printf("%d is a Happy number", num);
	else 
	    printf("%d is not a Happy number", num);
	    
	return 0;
}

/*
ouput:
19 is a Happy number

*/
