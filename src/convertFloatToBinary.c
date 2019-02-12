/*
Convert decimal fraction to binary number
Given an fraction decimal number n and integer k, convert decimal number n into equivalent binary number up-to k precision after decimal point.

Algorithm Part-1
Convert decimal to binary
1.Divide the number by 2 and store the remainder.
2.Assign the quotient as the number.
3.Repeat the steps till the quotient is zero.
4.Reverse the stored remainder which the binary equivalent of decimal.

Algorithm Part-2
Convert fractional integral to binary
1.Loop till precision.
    1.a.Multiply the fractional integral by 2.
    1.b.Check the first digit of resultant integral number.
    

*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h> 
#define PRECISION 5
#define MAX 100

char* getInteger(char* num){
    char *getInt=(char *)malloc(sizeof(char)*strlen(num));
    int i=0;
    while(*num && *num!='.'){
        getInt[i++]=*num++;
    }
    getInt[i]='\0';
    return getInt;
}//getAfterDecimalPoint

void printIntBinary(int num){
    int binary[MAX],i=0;
    while(num){
        binary[i++]=num%2;
        num/=2;
    }
    for(int k=i-1;k>=0;k--)
        printf("%d",binary[k]);
    
}//printIntBinary

void printFloatBinary(float num){
    int rem=(int)num;
    printf(".");
    for(int i=0;i<PRECISION;i++){
        num=num*2;
        printf("%d",(int)num);
        if((int)num==1)
            num-=1;
    }
}//printFloatBinary

int main(){
    char num[MAX];
    scanf("%s",&num);
    char *floatNum = strchr(num,'.');
    char *intNum=getInteger(num);
    printIntBinary(atoi(intNum));
    printFloatBinary(atof(floatNum));
    return 0;
}

/*
Input:
4.47
Output:
100.01111
*/
