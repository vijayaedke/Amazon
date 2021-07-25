/*
14. Longest Common Prefix
Easy
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/
int findPrefix(char *s1, char *s2){
   
    int i=0, j=0;
    
    while(i<strlen(s1) && j<strlen(s2) && s1[i]==s2[j]){
        i++;
        j++;
    }
    return i<j?i:j;    
}//findPrefix

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==1)
        return strs[0];
    int MAX = 1000;
    char *s1 = strs[0];
    char *match = NULL;
    for(int i=1;i<strsSize;i++){
        if(strlen(strs[i])<=0)
            return "";
        char *s2 = strs[i];
        printf("s1 = %s s2 = %s\n", s1, s2);
        int len = findPrefix(s1, s2);
        printf("len = %d MAX %d\n", len, MAX);

        if(MAX>len){
            match = NULL;
            match = (char *)malloc(sizeof(char) * 201);
            strncpy(match, s2, len);
            MAX = len;
        }//if
        
    }//for
    if(match!=NULL){
        match[MAX]='\0';
        return match;
    }
    return "";
}
/*
input:
["flower","flow","flight"]
["dog","racecar","car"]
["",""]
["ab","a"]
["abab","aba",""]


output:
fl"
""
""
"a"
""

*/
