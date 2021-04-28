/*
Matrix Chain Multiplication | DP-8
Difficulty Level : Hard
Last Updated : 08 Apr, 2021
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have: 

(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
Clearly the first parenthesization requires less number of operations.
Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i]. We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain. 

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 
There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input: p[] = {10, 20, 30}  
Output: 6000  
There are only two matrices of dimensions 10x20 and 20x30. So there 
is only one way to multiply the matrices, cost of which is 10*20*30
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findMatrixChainMultiplication(int *array, int size){
    if(size==0)
        return 0;
        
    int dp[size-1][size-1];
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            dp[i][j] = -1;
        }
    }
    
    for(int gap=0; gap<size-1; gap++){
        for(int i=0, j=gap; j<size-1; i++, j++){
            if(gap==0){
                dp[i][j] = 0;
            }
            else if(gap==1){
                dp[i][j] = array[i] * array[j] * array[j+1]; 
            }
            else{
                int min = INT_MAX;
                for(int cut=i; cut<j; cut++){
                    //left cut - i-->cut
                    //right ut - cut+1-->j
                    //multiple - i-->cut+1-->j+1
                    int lcut = dp[i][cut];
                    int rcut = dp[cut+1][j];
                    int multiple = array[i] * array[j] *array[j+1];
                    long tc = lcut + rcut + multiple;
                    min = tc<min?tc:min;

                }
                dp[i][j] = min;
            }//for
        }//for
        
    }//for
    
    return dp[0][size-2];
}//findMatrixChainMultiplication
int main() {
	//code
	int array[]= { 10, 20, 30, 40, 50, 60 };//  { 1, 2, 3, 4 };
	int size = sizeof(array)/sizeof(array[0]);
	printf("Min operation = %d", findMatrixChainMultiplication(array, size));
	
	return 0;
}

/*
output:
Min operation = 68000
*/
