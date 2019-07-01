/*
Rearrange a string in sorted order followed by the integer sum
Given a string containing uppercase alphabets and integer digits (from 0 to 9),
the task is to print the alphabets in the order followed by the sum of digits.
Input : AC2BEW3
Output : ABCEW5
Alphabets in the lexicographic order 
followed by the sum of integers(2 and 3).
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 256
#include<string.h>
int isChar(char ch){
    return (ch>=65 && ch<=91) || (ch>=97 && ch<=123);
}//isChar

char *getNum(int sum){
    char *buffer=(char *)malloc(5);
    int index=0;
    while(sum>0){
        buffer[index++]=(char)((sum%10)+'0');
        sum=sum/10;
    }//while
    buffer[index]='\0';
    // printf("Buffer =%s",buffer);
    return buffer;
}//getNum

char *getString(char *str){
    int map[MAX]={0};
    int sum=0,count=0;
    int size=strlen(str);
    while(*str){
        if(isChar(*str)){
            map[*str]+=1;
        }//if
        else{
            count++;
            sum+=(*str-'0');
        }//else
        *str++;
    }//while
    
    char *res=(char *)malloc(size-count+1);
    int k=0;
    for(int i=0;i<MAX;i++){
        while(map[i]>0){
            res[k++]=(char)i;
            map[i]--;
        }//if
    }//for
    
    char *numstr=getNum(sum);
    while(*numstr){
        res[k++]=*numstr;
        *numstr++;
    }//while
    
    return res;
}//getString

int main() {
    // char *str="AC2BEW3";
    char *str="ACCBA10D2EW30";
    printf("Sorted String = %s",getString(str));
    return 0;
}

/*
Sorted String = AABCCDEW6
*/
