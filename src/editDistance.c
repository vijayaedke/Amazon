/*
Edit Distance | DP-5
Difficulty Level : Medium
Last Updated : 17 Feb, 2021
 
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

Insert
Remove
Replace
All of the above operations are of equal cost. 

Examples: 

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations. 
Replace 'n' with 'r', insert t, insert a
Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution. 
 
What are the subproblems in this case? 
The idea is process all characters one by one staring from either from left or right sides of both strings. 
Let us traverse from right corner, there are two possibilities for every pair of character being traversed.  

m: Length of str1 (first string)
n: Length of str2 (second string)
If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values. 
-Insert: Recur for m and n-1
-Remove: Recur for m-1 and n
-Replace: Recur for m-1 and n-1

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z){
    return x<y?(x<z ? x:z):(y<z?y:z);
}//min

//recursive approach
// int findMinEditDistance(char *str, char *str1, int s1, int s2){
    
//     if(s1==0)
//         return s2;
    
//     if(s2==0)
//         return s1;
        
//     if(str[s1]==str1[s2])
//         return findMinEditDistance(str, str1, s1-1, s2-1);
    
//     return 1 + min(findMinEditDistance(str, str1, s1-1, s2),
//                   findMinEditDistance(str, str1, s1, s2-1),
//                   findMinEditDistance(str, str1, s1-1, s2-1));
    
// }//findMinEditDistance

//dynamic programming approach
int findMinEditDistance(char *str, char *str1, int s1, int s2){
    if(s1==0)
        return s2;
    
    if(s2==0)
        return s1;
    
    int dp[s1+1][s2+1];
    for(int i=0;i<=s1;i++){
        dp[i][0] = i;
    }//for
    
    for(int i=0;i<=s2;i++){
        dp[0][i] = i;
    }//for
    
    for(int i=1; i<=s1; i++){
        for(int j=1; j<=s2; j++){
            if(str[i]==str1[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+min( dp[i][j-1], dp[i-1][j-1], dp[i-1][j]);
        }//for j
    }//for i
    return dp[s1][s2];
}//findMinEditDistance

int main() {
	//code
    // char *str="geek", *str1="gesek";
    char *str="sunday", *str1="saturday";
    int s1 = strlen(str), s2=strlen(str1);
    printf("Min operations %d", findMinEditDistance(str, str1, s1-1, s2-1));
	return 0;
}
