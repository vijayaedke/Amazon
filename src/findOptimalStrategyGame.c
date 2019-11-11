/*
Optimal Strategy for a Game | DP-31
Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. 
We play a game against an opponent by alternating turns. In each turn, a player selects
either the first or last coin from the row, removes it from the row permanently, and 
receives the value of the coin.Determine the maximum possible amount of money we can 
definitely win if we move first.
1) 5, 3, 7, 10 : The user collects maximum value as 15(10 + 5)
2) 8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)
Does choosing the best at each move give an optimal solution?
No. In the second example, this is how the game can finish:
1.
…….User chooses 8.
…….Opponent chooses 15.
…….User chooses 7.
…….Opponent chooses 3.
Total value collected by user is 15(8 + 7)
2.
…….User chooses 7.
…….Opponent chooses 8.
…….User chooses 15.
…….Opponent chooses 3.
Total value collected by user is 22(7 + 15)
So if the user follows the second game state, maximum value can be collected although the first move is not the best.
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}//max

int min(int a, int b){
    return a<b?a:b;
}//min

int findOptimalStrategy(int *array, int n){
    int matrix[n][n];
    
    for(int loop=0;loop<n;loop++){
        for(int i=0,j=loop; j<n; j++,i++){
           int x = i+2 <= j ? matrix[i+2][j] : 0;
           int y = i+1 <= j-1 ? matrix[i+1][j-1] : 0;
           int z = i <= j-2 ? matrix[i][j-2] : 0;
            
           matrix[i][j] = max(array[i] + min(x,y) , array[j]+min(y, z) );    
        }//for i,j
    }//for loop
    return matrix[0][n-1];
}//findOptimalStrategy

int main() {
	//code
    int array[]={5,3,7,10};
    int n = sizeof(array)/sizeof(array[0]);
    printf("%d\n", findOptimalStrategy(array, n));
    
    int arr1[] = { 8, 15, 3, 7 }; 
    n = sizeof(arr1) / sizeof(arr1[0]); 
    printf("%d\n", findOptimalStrategy(arr1, n)); 
	return 0;
}

/*
output
15
22
*/
