/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int firstUniqChar(char * str){
    int hashtable[26]={0};
    int index=-1, len=strlen(str);
    if(len==0)
        return -1;
    
    if(len==1)
        return 0;
    
    for(int i=0;i<len;i++)
        hashtable[str[i]-97]++;
    
    for(int i=0;i<len;i++){
        if(hashtable[str[i]-97]==1){
            index=i;
            break;
        }//if
    }//for
    
    
    return index;
}

int main() {
	//code
    // char *str = "leetcode";
    // char *str = "loveleetcode";
    // char *str="cc";
    char *str="cccaabadb";
    printf("%d" ,firstUniqChar(str));

	return 0;
}

/*
output :
0
2
-1
7
*/
