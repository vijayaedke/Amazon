/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct set{
  int index;
  char *ch;
};
int check(int num, struct set s[16]){
    int index=0;
    for(int i=0;i<16;i++){
        // printf("%d %s\n", s[i].index, s[i].ch);
        if(num < s[i].index){
             return i-1;
        }
    }   //for 
    return 15;
}//check

char* printRoman(int num){
    struct set s1[16];//= (struct set **)malloc(sizeof(struct set) * 16);
    s1[0].index = 1; s1[0].ch="I";
    s1[1].index = 4; s1[1].ch="IV";
    s1[2].index = 5; s1[2].ch="V";
    s1[3].index = 6; s1[3].ch="VI";
    s1[4].index = 9; s1[4].ch="IX";
    s1[5].index = 10; s1[5].ch="X";
    s1[6].index = 40; s1[6].ch="XL";
    s1[7].index = 50; s1[7].ch="L";
    s1[8].index = 60; s1[8].ch="LX";
    s1[9].index = 90; s1[9].ch="XC";
    s1[10].index = 100; s1[10].ch="C";
    s1[11].index = 400; s1[11].ch="CD";
    s1[12].index = 500; s1[12].ch="D";
    s1[13].index = 600; s1[13].ch="DC";
    s1[14].index = 900; s1[14].ch="CM";
    s1[15].index = 1000; s1[15].ch="M";

    if(num==0)
        return "0";

    char *res = (char *)malloc(sizeof(char) * 1000);
    res[0]='\0';
    
    int index=0;
    
    while(num){
        int get_index = check(num, s1);
        strcat(res,s1[get_index].ch);
        // printf("%s", s1[get_index].ch);
        num-=s1[get_index].index;
    }//while

    // printf("%s\n", res);
    return res;
    
}//printRoman

int main() {
	//code

    printf("%s\n", printRoman(58));

	return 0;
}
/*

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"

Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/
