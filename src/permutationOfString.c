/*
Write a program to print all permutations of a given string
Difficulty Level : Medium
Last Updated : 03 Dec, 2020
A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements of an 
ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation. 

Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

Below are the permutations of string ABC. 
ABC ACB BAC BCA CBA CAB

Recommended: Please solve it on “PRACTICE ” first, before moving on to the solution. 
 
Here is a solution that is used as a basis in backtracking.

NewPermutation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *str, int i, int j){
    char ch = str[i];
    str[i] = str[j];
    str[j] = ch;
}//swap

void permutation(char *str, int len, int curr, int *map, char *newstring){
    if(curr>=len){
        printf("%s\n", newstring);
        return;
    }
    
    for(int i=0; i<len; i++){
        char ch = str[i];
        if(map[ch - 97]){
            map[ch - 97]--;
            newstring[curr] = ch;
            permutation(str, len, curr+1, map, newstring);
            map[ch - 97]++;
        }
    }//for
  
}//permutation

int main() {
	//code
    char str[]="abc";
    int map[26] = {0};
    for(int i=0;i<strlen(str);i++){
        map[str[i]-97]++;
    }
    
    char *newstr = (char *)malloc(sizeof(char) * strlen(str)+1);
    permutation(str, strlen(str), 0, map, newstr);
	return 0;
}
/*
abc
acb
bac
bca
cab
cba

*/
