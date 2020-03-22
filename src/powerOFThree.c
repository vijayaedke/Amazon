/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getlog(int num, int base){
    return log10(num)/log10(base);
}//getlog



int isPowerOfThree(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
        
    double val = getlog(n, 3);
    int truncate = (int)val;
    printf("%d %.15f", truncate, val);
    
    if(val==truncate)
        return 1;
    else
        return 0;
}//isPowerOfThree

int main() {
    // int num=243;
    int num=4782968;
    printf("\n%d", isPowerOfThree(num));
	return 0;
}


/*output:
13 13.999999809691570
0
*/
