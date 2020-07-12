/*
Manacher’s Algorithm – Linear Time Longest Palindromic Substring
Given a string, find the longest substring which is palindrome.

if the given string is “forgeeksskeegfor”, the output should be “geeksskeeg”
if the given string is “abaaba”, the output should be “abaaba”
if the given string is “abababa”, the output should be “abababa”
if the given string is “abcbabcbabcba”, the output should be “abcbabcba”


Algorithm:
1. Process a string with delimiter in between eg : str="abaabc" ==> "$a#b#a#a#b#c@". Add start and end delimiter.
2. Initializa the LPS(Longest Palindrome Substring) len using an array with size 2*len(string) +1 == len(processedString);
3. Calculate the LPS and update LPS :
  3.a Initialize the centre, mirror_line and right boundary to the start of a string.
     centre - determines if a string is palindrome there by dividing the string in middle.
     mirror_line - mirror the LPS value of left to right from the centre palindrome.
     right - boundary till where the palindrome string has been calculated.
  3.b With mirroring process of coping the LPS value from left of mirror_line to right of mirror_line has 3 condition :
      eg: str   $  a  #  b  #  a  #  a  #  b  #  c  @
          index 0  1  2  3  4  5  6  7  8  9 10 11 12
          lps   0  0  0  0  0  0  0  0  0  0  0  0  0
      consider : Case 1:
                 mirror_line at index 6 , left boundary at index 0  and right boundary at index 11. A string is said to be palindrome when it's left side is 
                 equivalent to right side given a mid point. So when traversed left side of the right, we can copy the LPS len from left of centre to right of
                 string. However, in the above case, when mirroring the LPS of index 1 with index 11 isn't equivalent due to mismatch case.
                 Case 2:
                 Every character in string is a palindrome itself hence, it'll be always 1 for a character and for delimiter 0. When the mirroring with range, 
                 check for minimum of (right_boundary - current index) and mirror LPS.
                 Case 3:
                 If current character is beyond the right boundary, extend the boundaries thereby setting the centre to current.
4. Return the max value among the LPS array. 
        
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *processString(char *str, int len){
    char *processString = (char *)malloc(sizeof(char) * (2*len+2));
    
    processString[0]='$';
    for(int i=0, j=1;i<len;i++,j++){
        processString[j++] = str[i];
        processString[j] = '#';
    }
    processString[2*len]='@';
    processString[2*len+1]='\0';

    
    return processString;
}//processString

int min(int a, int b){
    return a<b?a:b;
}//min

int findLongestPalindromicString(char *str, int len){
    int max=0, centre=0, right=0;
    int lps[2*len+1];
    
    str = processString(str, len);
    lps[0]=0;
    int mirror_line=0;
    
    for(int i=1;i<strlen(str)-1;i++){
        mirror_line = 2*centre-1;
        
        if(i < right)
            lps[i] = min (abs(i-right), lps[mirror_line]);
        
        while(str[i + (1 + lps[i])] == str[i - (1 + lps[i])])
            lps[i]++;
        
        if( i+lps[i] > right){
            centre = i;
            right = i+lps[i];
            max = max<lps[i]?lps[i]:max;
        }//if
    }//for
    // printf("\nstart = %d", ((mirror_line-centre)/2)-1);
    // int start = ((mirror_line-centre)/2)-1;
    // printf("\nend = %d", start+((2*max)-1));
    // int end = start+((2*max)-1);
    
    // for(int i=start;i<end;i++){
    //     if(str[i]!='#')
    //         printf("%c", str[i]);
    // }

    return max;
    
}//findLongestPalindromicString

int main() {
	//code
	char *str = "forgeeksskeegfor";
	printf("\nMax = %d",findLongestPalindromicString(str, strlen(str)));
	return 0;
}
