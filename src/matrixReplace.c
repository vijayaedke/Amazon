/*
Given a matrix of ‘O’ and ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’
Last Updated: 22-07-2020
Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it. 
Examples: 
 

Input: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Output: mat[M][N] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'X', 'X', 'X'},
                      {'O', 'X', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'O', 'X', 'O'},
                      {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Input: mat[M][N] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'O', 'O', 'X'}
                     {'X', 'O', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
 

Input: mat[M][N] =  {{'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'X', 'X'}
                     {'X', 'X', 'O', 'O'}
                    };
*/
// A C++ program to replace all 'O's with 'X''s if surrounded by 'X' 
#include<stdio.h> 
#include<stdlib.h> 

// Size of given matrix is M X N 
#define M 6 
#define N 6 
int flag =0;

void util(char matrix[][N], int i, int j, int visited[][N]){

    if(i<0 || i>=M || j<0 || j>=N)
        return;
        
    if(!visited[i][j] ){
        // printf("%d %d", i, j);
        if (matrix[i][j]=='O' && (i==0 || j==0 || i==M-1 || j==N-1) ){
            flag = 1;
            visited[i][j]=1;
            return;
        }//if
        
        visited[i][j] = 1;
    }
    else
        flag = 1;
   
}//util

void print(char matrix[][N]){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            printf("%c\t", matrix[i][j]); 
        }//for j
        printf("\n");
    }//for i
}//print

void checkMatrix(char matrix[][N]){
    int visited[M][N] = {{0}};
    
    for(int i=1;i<M-1;i++){
        for(int j=1;j<N-1;j++){
            flag = 0;
            
            if(matrix[i][j]=='O'){
                visited[i][j] = 1;
                //up
                util(matrix, i-1, j, visited);
                //down
                util(matrix, i+1, j, visited);
                //left
                util(matrix, i, j-1, visited);
                //right
                util(matrix, i, j+1, visited);
            }
            // printf("flag =  %d\n", flag);
            if(flag==0)
                matrix[i][j] = 'X';
        }//for j
    }//for i
	print(matrix);
}//checkMatrix


int main() 
{ 
	char matrix[][N] =
	                {{'X', 'O', 'X', 'O', 'X', 'X'}, 
                     {'X', 'O', 'X', 'X', 'O', 'X'}, 
                     {'X', 'X', 'X', 'O', 'X', 'X'}, 
                     {'O', 'X', 'X', 'X', 'X', 'X'}, 
                     {'X', 'X', 'X', 'O', 'X', 'O'}, 
                     {'O', 'O', 'X', 'O', 'O', 'O'}, 
                    }; 
	checkMatrix(matrix);
	return 0; 
} 
