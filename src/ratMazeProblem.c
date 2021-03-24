/*
Rat in a Maze Problem - I 
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/


#include <stdio.h>
#include <stdlib.h>
#define N 4

int check(int matrix[][N], int row, int col){
    return row<N && col<N && matrix[row][col]==1; 
}//check

void util(int matrix[][N], int i , int j){
    if(i==N-1 && j==N-1)
        return;
    
    if(check(matrix, i+1, j)){
        printf("D");
        matrix[i+1][j] = 2;
        util(matrix, i+1, j);
    }
    else if(check(matrix, i-1, j)){
        printf("U");
        matrix[i-1][j] = 2;
        util(matrix, i-1, j);
    }
    else if(check(matrix, i, j+1)){
        printf("R");
        matrix[i][j+1] = 2;
        util(matrix, i, j+1);
    }
    else if(check(matrix, i, j-1)){
        printf("D");
        matrix[i][j-1] = 2;
        util(matrix, i, j-1);
    }
    
}//util

int main() {
    int matrix[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1}, 
    {1, 1, 0, 0},
    {0, 1, 1, 1}  
    };
    
    if(matrix[N-1][N-1]==0){
        printf("-1");
        return 0;
    }
    
    util(matrix, 0, 0);
	
	return 0;
}

/*
output :
DDRDRR
*/
