/*

Maximum path sum in matrix
Given a matrix of N * M. Find the maximum path sum in matrix. The maximum path is sum of all elements from first row to last row where you are allowed to move only down or diagonally to left or right. You can start from any element in first row.

Examples:

Input : mat[][] = 10 10  2  0 20  4
                   1  0  0 30  2  5
                   0 10  4  0  2  0
                   1  0  2 20  0  4
Output : 74
The maximum sum path is 20-30-4-20.

Input : mat[][] = 1 2 3
                  9 8 7
                  4 5 6
Output : 17
The maximum sum path is 3-8-6.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findSumMatrix(int matrix[4][6], int m, int n){
// int findSumMatrix(int matrix[3][3], int m, int n){
    int max = INT_MIN;
    int c_index=0;
    
    for(int i=0;i<n;i++){
        if(max < matrix[0][i]){
            max = matrix[0][i];
            c_index=i;
        }//if
    }//for
    
  
    // printf("\n\nMax=  %d, c_index = %d\n", max, c_index);
    int sum=max, index=0;
    for(int i=1;i<m;i++){
        max=INT_MIN;
        for(int j=c_index-1;j<=c_index+1 ;j++){
            //  printf("\nCurrent num = %d j=%d cindex = %d", matrix[i][j], j, c_index);

            if( (j>=0 && j<n) && max<matrix[i][j]){
                max = matrix[i][j];
                index = j;
                // printf("\nMax = %d, index = %d", max, j);
            }//if
        }//for j
        sum+=max;
        c_index = index;
    }//for i
    
    return sum;
}//findSumMatrix

int main() {
	int matrix[4][6] = {
	    {10, 10 , 2,  0 ,20,  4},
        {1 , 0 , 0 , 30 , 2 , 5},
        {0 ,10 , 4 , 0 , 2 , 0},
        {1 , 0,  2 , 20,  0 , 4}
	};
    // int matrix[3][3] = {
    //     {1,2,3},
    //     {9,8,7},
    //     {4,5,6}
    // };
    // printf("\nSum of matrix = %d ", findSumMatrix(matrix, 3, 3));
    printf("\nSum of matrix = %d ", findSumMatrix(matrix, 4, 6));

	return 0;
}
