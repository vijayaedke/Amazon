#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define chars 256


void findMinWindowString(char *str){
    int visited[chars]={0};
    int dist_char=0;
    
    for(int i=0;i<strlen(str);i++){
        if(visited[str[i]]==0){
            visited[str[i]]=1;
            dist_char++;

        }//if
    }//for
    // printf("hi");
    int left=-1, right=0, minWindow=INT_MAX, count=0;
    int hashtable[chars] = {0};
    for(int j=0;j<strlen(str);j++){
        hashtable[str[j]]++;
        
        if(hashtable[str[j]]==1)
            count++;
        // printf("h9");
        if(count==dist_char){
            
            while(hashtable[str[right]]>1){
                if(hashtable[str[right]]>1)
                    hashtable[str[right]]--;
                right++;
            }//while
            
            int windowslen = j - right +1;
            if(minWindow>windowslen){
                minWindow = windowslen;
                left=right;
            }//if
        }//if
    }//for
    
   for(int i=left; i<minWindow+left; i++)
        printf("%c", str[i]);
}//findMinWindowString

int main() {
    char *str= "aabcbcdbca"; 
   findMinWindowString(str);
    
    return 0;
}