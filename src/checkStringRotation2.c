/*
Check if a string can be obtained by rotating another string 2 places
Given two strings, the task is to find if a string can be obtained by rotating another string two places.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200


int antiClockwise(char *str1,char *str2,int length){
    char temp[2];
    memcpy(temp,&str1[0],2);
    
    for(int i=2;i<strlen(str1);i++){
        str1[i-2]=str1[i];
    }
    
    memcpy(&str1[length-2],temp,2);
    
    if(strcmp(str1,str2)==0)
        return 1;
    return 0;
}


int clockwise(char *str1,char *str2,int length){
    char temp[2];
    memcpy(temp,&str1[length-2],2);
 
    for(int i=length-3;i>=0;i--){
        str1[i+2]=str1[i];
    }
    
    memcpy(&str1[0],temp,2);
    
    if(strcmp(str1,str2)==0)
        return 1;
    return 0;
    
}//clockwise

int checkStringRotation(char *str1,char *str2){
    int length = strlen(str1);
    char base_string1[length],base_string2[length];
    strcpy(base_string1,str1);
    strcpy(base_string2,str1);
    
    if( antiClockwise(base_string1,str2,length) ||  clockwise(base_string2,str2,length) )
        return 1;
    
    return 0;
}//checkStringRotation

int main(){
    int testcases;
    scanf("%d",&testcases);
    
    while(testcases--){
        char str1[MAX],str2[MAX];
        scanf("%s%s",&str1,&str2);
        if(checkStringRotation(str1,str2))
            puts("Yes");
        else
            puts("No");
    }//while
    
    return 0;
}


/*
inputs :
2
amazon // rotated clockwise
onamaz
amazon // rotated anti-clockwise
azonam

output : 
Yes
Yes


*/
