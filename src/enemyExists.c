/*
Check if all enemies are killed with bombs placed in a matrix
17-01-2019
Given a Character matrix as input, the task is to check whether all the enemies are killed or not based on below conditions:

1. The matrix can contain 3 characters
X –> Denotes the War area.
B –> Denotes the bomb.
E –> Denotes the Enemies.

2. Bomb ‘B’ can blast in only horizontal and vertical directions from one end to another.

3. If all enemies are killed by the present bombs, print Yes, else print No

Examples:
Input: matrix =
XXEX
XBXX
XEXX
XXBX 
Output: Yes

Input: matrix =
XXEX
XBXX
XEXX
XXXX
Output: No
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **valid(char **matrix, int i, int j, int rows, int cols){
    //check and update current rows (rotation)
    if(i==rows) i=0; if(i<0) i=rows-1;
    //check and update current cols (rotation)
    if(j==cols) j=0; if(j<0) j=cols-1;
    //update the matrix
    if(i>=0 && j>=0 && matrix[i][j]=='E'){
        matrix[i][j] = 'X';
    }
    return matrix;
}//valid

char **check(char **matrix, int i, int j, int rows, int cols){
    //check down
    matrix = valid(matrix, i+1, j, rows, cols);
    //check up
    matrix = valid(matrix, i-1, j, rows, cols);
    //check right
    matrix = valid(matrix, i, j+1, rows, cols);
    //check left
    matrix = valid(matrix, i, j-1, rows, cols);

    return matrix;
}//check

void printMatrix(char **matrix, int rows, int cols){
    for(int i=0;i<rows;i++){
	    for(int j=0;j<cols;j++){
	        printf("%c\t", matrix[i][j]);
	    }//for i
	    printf("\n");
	}//for j
}//printMatrix

int enemyExists(char **matrix, int rows, int cols){
    if(matrix==NULL)
        return 0;
        
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]=='B')
                matrix = check(matrix, i, j, rows, cols);
        }//for j
    }//for i

    printf("\nResultant matrix\n");
	printMatrix(matrix, rows, cols);

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]=='E')
                return 1;
        }//for j
    }//for i
    return 0;
}//enemyExists

int main() {
	//code
	int rows=4, cols=4;
	char **matrix = (char **)malloc(sizeof(char *) * rows);
	
	for(int i=0;i<cols;i++)
	    matrix[i] = (char *)malloc(sizeof(char) * cols);
	   
	for(int i=0;i<rows;i++)
	    scanf("%s", matrix[i]);
	
    printf("\nActual matrix\n");	
	printMatrix(matrix, rows, cols);

    if(enemyExists(matrix, rows, cols))
        printf("No");
    else
        printf("Yes");
	
	return 0;
}

/*
input : 

XXEX
XBXX
XEXX
XXXX

output: 

Actual matrix
X	X	E	X	
X	B	X	X	
X	E	X	X	
X	X	X	X	

Resultant matrix
X	X	E	X	
X	B	X	X	
X	X	X	X	
X	X	X	X	
No


input:
XXEX
XBXX
XEXX
XXBX

output:

Actual matrix
X	X	E	X	
X	B	X	X	
X	E	X	X	
X	X	B	X	

Resultant matrix
X	X	X	X	
X	B	X	X	
X	X	X	X	
X	X	B	X	
Yes

*/
