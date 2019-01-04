/*
Replace all ‘0’ with ‘5’ in an input Integer
Given a integer as a input and replace all the ‘0’ with ‘5’ in the integer.
*/
#include<stdio.h>
#include<stdlib.h>

int replace0By5(int num){
    int sum=0,rem;
    
    while(num>0){
        rem = num%10;
        if(rem==0)
            sum = 5 + (sum*10);
        else
            sum = rem + (sum*10);
        num = num/10;
    }//while
    
    num=0;
    while(sum>0){
        rem = sum%10;
        num = rem + (num*10);
        sum = sum/10;
    }

    return num;
}//replace0By5

int main() {
   int testcases;
   scanf("%d",&testcases);
   while(testcases--){
       int num;
       scanf("%d",&num);
       printf("%d\n",replace0By5(num));
   }//while
   
   return 0;
}


/*
input:
3
1020
102
10120

output :
1525
152
15125

*/
