/*
67. Add Binary
Easy
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

char *strrev(char *s){
    int i=0, j=strlen(s)-1;
    
    while(i<=j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    
    return s;
}

char * addBinary(char * a, char * b){
    int len1 = strlen(a), len2=strlen(b);
    char *res = (char *)malloc(sizeof(char) * 10000);
    
    int index=0, carry=0,sum=0, i=len1-1, j=len2-1;
    
    while(j>=0 && i>=0){
        
        if(a[i]=='1' && b[j]=='1' && carry==0){
            printf("in here\n");
            carry =1;
            sum = 0;
        }
        else if(a[i]=='1' && b[j]=='1' && carry==1){
            carry =1;
            sum = 1;
        }
        else{
            sum = carry ^ ((a[i]-48) ^ (b[j]-48));
            carry = carry & ((a[i]-48) ^ (b[j]-48));
        }
        
        res[index++] = sum+48;
        i--;
        j--;
        printf("sum = %c, carry %d\n", res[index-1], carry);
    }//while
    
    while(j>=0){
        sum = (b[j]-48) ^ carry;
        carry = carry & (b[j]-48);
        res[index++] = sum+48;
        printf("sum = %c, carry %d\n", res[index-1], carry);
        j--;
    }
    
    while(i>=0){
        sum = (a[i]-48) ^ carry;
        carry = carry & (a[i]-48);
        res[index++] = sum+48;
        printf("sum = %c, carry %d\n", res[index-1], carry);
        i--;
    }
    
    if(carry)
        res[index++] = carry+48;
    
    res[index] = '\0';
    printf("%s res\n",res);
    return strrev(res);
}

/*
input : 
"11"
"1"
"1010"
"1011"
"110010"
"10111"
"1111"
"1111"

output:
"100"
"10101"
"1001001"
"11110"
*/
