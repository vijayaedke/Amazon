/*
Sudoku | Backtracking-7
Difficulty Level : Hard

Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, 
and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9. 
Input:
grid = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }
Output:
          3 1 6 5 7 8 4 9 2
          5 2 9 1 3 4 7 6 8
          4 8 7 6 2 9 5 3 1
          2 6 3 4 1 5 9 8 7
          9 7 4 8 6 3 1 2 5
          8 5 1 7 9 2 6 4 3
          1 3 8 9 4 7 2 5 6
          6 9 2 3 5 1 8 7 4
          7 4 5 2 8 6 3 1 9

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 9

int check(int matrix[][N], int row, int col, int x){
    
    if(row<0 || row>=N || col<0 || col>=N)
        return 0;
        
    for(int i=0;i<N;i++){
        if(matrix[i][col]==x)
            return 0;
    }//for
    
    for(int i=0;i<N;i++){
        if(matrix[row][i]==x)
            return 0;
    }//for
    
    int checkRow = row - row%3;
    int checkCol = col - col%3;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[i+checkRow][j+checkCol] == x)
                return 0;
        }//for j
    }//for i
    return 1;
}//check

void print(int matrix[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d\t", matrix[i][j]);
        }//for j
        printf("\n");
    }//for i
}//print


void solveSudoku(int matrix[][N], int i, int j){
    if(i>=N){
        print(matrix);
        return;
    }//if
    
    if(j>=N){
        i=i+1;
        j=0;
    }
    
    if(matrix[i][j]==0){
        for(int num=1;num<=9;num++){
            if(check(matrix, i, j, num)){
                matrix[i][j] = num;
                solveSudoku(matrix, i, j+1);
                matrix[i][j] = 0;
            }
        }//for
    }//if
    else
        solveSudoku(matrix, i, j+1);
    
}

int main() {
    int matrix[N][N]={{3 ,0 ,6 ,5 ,0 ,8 ,4 ,0 ,0},
                    {5 ,2 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
                    {0 ,8 ,7 ,0 ,0 ,0 ,0 ,3 ,1},
                    {0 ,0 ,3 ,0 ,1 ,0 ,0 ,8 ,0},
                    {9 ,0 ,0 ,8 ,6 ,3 ,0 ,0 ,5},
                    {0 ,5 ,0 ,0 ,9 ,0 ,6 ,0 ,0},
                    {1 ,3 ,0 ,0 ,0 ,0 ,2 ,5 ,0},
                    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,4},
                    {0 ,0 ,5 ,2 ,0 ,6 ,3 ,0 ,0}};
                    
    solveSudoku(matrix,0,0);
	return 0;
}


/*
3	1	6	5	7	8	4	9	2	
5	2	9	1	3	4	7	6	8	
4	8	7	6	2	9	5	3	1	
2	6	3	4	1	5	9	8	7	
9	7	4	8	6	3	1	2	5	
8	5	1	7	9	2	6	4	3	
1	3	8	9	4	7	2	5	6	
6	9	2	3	5	1	8	7	4	
7	4	5	2	8	6	3	1	9	


*/
