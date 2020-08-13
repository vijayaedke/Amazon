/*
Modular Exponentiation (Power in Modular Arithmetic)
Last Updated: 28-03-2020
Given three numbers x, y and p, compute (xy) % p.

Examples :

Input:  x = 2, y = 3, p = 5
Output: 3
Explanation: 2^3 % 5 = 8 % 5 = 3.

Input:  x = 2, y = 5, p = 13
Output: 6
Explanation: 2^5 % 13 = 32 % 13 = 6.
 
 
Write a program to calculate pow(x,n)
Last Updated: 05-07-2019
Given two integers x and n, write a function to compute xn. We may assume that x and n are small and overflow doesn’t happen.

Examples :

Input : x = 2, n = 3
Output : 8

Input : x = 7, n = 2
Output : 49
*/
#include <stdio.h>
#include <stdlib.h>
int res=1;

int power(int x, int y){
    if(y==0)
        return 1;
    else if(y%2==0){
        res = x * power(x, y/2);
        return res * res;
    }
    else
        return res * power(x, y-1);
}

int mod(int x, int y, int m){
    if(y==0)
        return 1;
    else if(y%2==0){
        res = x * mod(x, y/2, m);
        return (res%m * res%m)%m;
    }
    else
        return ((res%m) * (mod(x, y-1,m)%m))%m;
}

int main() {
	//code
	int x=5,y=2,m=7;
	
    printf("%d",mod(x, y, m));
	return 0;
}
