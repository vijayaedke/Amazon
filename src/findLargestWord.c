/*
Find largest word in dictionary by deleting some characters of given string
Giving a dictionary and a string ‘str’, find the longest string in dictionary which can be formed by deleting some characters of the given ‘str’.

Examples:

Input : dict = {"ale", "apple", "monkey", "plea"}   
        str = "abpcplea"  
Output : apple 

Input  : dict = {"pintu", "geeksfor", "geeksgeeks", 
                                        " forgeek"} 
         str = "geeksforgeeks"
Output : geeksgeeks
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 1000

int isSubsequence(char *str1, char *str2){
    int j=0;
    int len1=strlen(str1), len2=strlen(str2);
    for(int i=0; i<len2 && j<len1; i++){
        if(str1[j]==str2[i])
            j++;
    }//for
    
    return j==len1;
    
}//isSubsequence

char* subsequence(char str[n], char dict[n][n], int size){
    int length =0;
    char *result = (char *)malloc(sizeof(char) * n);
    for(int i=0; i<size; i++){
        if(length < strlen(dict[i]) && isSubsequence(dict[i], str)){
            length = strlen(dict[i]);
            strcpy(result, dict[i]);
        }//if
    }//for
    printf("Word %s with length", result);
    return result;
}//subsequence

int main() {
	char dict[][n] = {"ale", "apple", "monkey", "plea"}; 
    char str[n] = "abpcplea" ;
    int size = sizeof(dict)/sizeof(*dict);
    int length = strlen(subsequence(str, dict, size));
    printf(" %d", length);
	return 0;
}

/*output : 
Word apple with length 5

*/
