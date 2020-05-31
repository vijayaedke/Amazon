/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
11111011111111101011
01111111111110111110
10111001101111111111
11110111111111111111
10011111111111111111
10111111011101110111
01111111111101101111
11111111111101111011
11111111110111111111
11111111111111111111
01111111011111111111
11111111111111111111
11111111111111111111
11111011111110111111
10111110111011110111
11111111111101111110
11111111111110111100
11111111111111111111
11111111111111111111
11111111111111111111

output:1
*/

//Using DFS approach
#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 20

int isSafe(int **grid, int i, int j){
    // printf("\ni j %d %d\n", i, j);
    return (i>=0 && i<ROWS) && (j>=0 && j<COLS) && grid[i][j]==1;
}//isSafe

int **init(int m, int n){
    int **visited = (int **)malloc(sizeof(int *) * m);
    for(int i=0;i<m;i++){
        visited[i] = (int *)malloc(sizeof(int) * n);
    }//for i
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }//for j
    }//for i
    return visited;
}//init

int fillMatrix(int **grid, int **visited, int i, int j){
    if(grid[i][j]==0) 
        return 0;
    
    visited[i][j] = 1;
    if(isSafe(grid, i+1, j) && !visited[i+1][j]){
        fillMatrix(grid, visited, i+1, j);
    }//isSafe
    
    
    if(isSafe(grid, i-1, j) && !visited[i-1][j]){
        fillMatrix(grid, visited, i-1, j);
    }//isSafe
    
    
    if(isSafe(grid, i, j+1) && !visited[i][j+1]){
        fillMatrix(grid, visited, i, j+1);
    }//isSafe
    
    
    if(isSafe(grid, i, j-1) && !visited[i][j-1]){
        fillMatrix(grid, visited, i, j-1);
    }//isSafe

    return 1;
}//fillMatrix

int numberOfIsland(int **grid, int m, int n){
    int **visited = init(m, n);
    int numOfIsland = 0;

    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && visited[i][j]==0){
                fillMatrix(grid, visited, i, j);
                numOfIsland++;
            }//if
        }//for j
    }//for i
    
    
    return numOfIsland;
    
}//numberOfIsland

int main() {

    int **array = (int **)malloc(sizeof(int *)*ROWS);
    for(int i=0;i<ROWS;i++)
        array[i] = (int *)malloc(sizeof(int) * COLS);
        
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            scanf("%d",&array[i][j]);
        }//for j
    }//for i
    
	printf("\ntime taken %d", numberOfIsland(array, ROWS, COLS));
	
	return 0;
}

/*
input : 
1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 0 1 1 1 0 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 0 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

output : 
time taken 1

*/
