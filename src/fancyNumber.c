/*
Check if a given number is Fancy
A fancy number is one which when rotated 180 degrees is the same. Given a number, find whether it is fancy or not.

180 degree rotations of 6, 9, 1, 0 and 8 are 9, 6, 1, 0 and 8 respectively

Input:  num =  96
Output: Yes
If we rotate given number by 180, we get same number

Input:  num =  916
Output: Yes
If we rotate given number by 180, we get same number

Input:  num =  996
Output: No

Input:  num =  121
Output: No

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fancy(char *num){
    int n[10];
    
    for(int i=0;i<10;i++)
        n[i]=-1;
        
    n[0]=0;
    n[1]=1;
    n[8]=8;
    n[6]=9;
    n[9]=6;
    
    
    int l=0, r=strlen(num)-1;
    
    while(l<=r){
        // printf("%d %d %d %d\n", l, r, num[l]-48, num[r]-48);
        if(n[num[l]-'0']==-1 || (n[num[l]-'0'])!=(num[r]-'0'))
            return 0;
        l++;
        r--;
    }//while
    
    return 1;
}//int

int main() {
	//code
    char *num="121";
    //char *num="96";
    if(fancy(num))
        printf("Yes");
    else
        printf("No");
	return 0;
}

/*
Input : 121
output: No

Input : 96
Output : Yes

*/
