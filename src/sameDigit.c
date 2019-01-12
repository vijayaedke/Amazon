/*
Count numbers with same first and last digits
Given an interval, the task is to count numbers which have same first and last digits. For example, 1231 has same first and last digits.

Examples:

Input  : start = 7,  end : 68
Output : 9
Number with same first and last digits are,
7 8 9 11 22 33 44 55 66.

Input  : start = 5,  end : 40
Output : 8

Solution : 
1. Intializa start and end range of numbers to be checked and counter variable
    1.a Get first digit = num / 10
    1.b Get last digit = num % 10
    1.c Check if last_digit == first_digit and ( first_digit==0 and last_digit > 0 )
        to check single digit
            1.c.a increment count
2. Return count
*/

#include<stdio.h>
#include<stdlib.h>

int countSameDigits(int start,int end){
    int count=0;
    for(int i=start;i<=end;i++){
        int first_digit = i/10;
        int last_digit = i%10;
        if( first_digit==last_digit || (first_digit==0&&last_digit>0))
            count++;
    }//for
    return count;
}//countSameDigits

int main(){
    int testcases;
    scanf("%d",&testcases);
    while(testcases--){
        int start,end;
        scanf("%d%d",&start,&end);
        printf("%d\n",countSameDigits(start,end));
    }//while
    return 0;
}

/*
Input :
1
7 68

output : 
9
*/
