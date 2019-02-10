/*
Arthur needs to hang  posters on his wall. Standing on the ground he can reach upto a height of . Each poster is to be bolted at a 
certain height above the ground level, described by the array . Each poster also has some length, defined by the array .To hang a 
poster properly, Arthur needs to hold atleast 50% of the length of the poster and poster is to be bolted at a point which is 25% from 
its top.Image Arthur wants to know what is the minimum height of the ladder he should buy, in order to hang all the wall posters. 
The ladder is only available in integral heights. Arthur can reach any height upto the maximum possible height.
Input Format
The first line of the input contains two space separated integers,  and .
The next line contains  space separated integers, denoting the elements of the array .
The last line contains  space separated integers, denoting the elements of the array .
Constraints
1 ≤  < 10^9
1 ≤  ≤ 10^5
1 ≤ i ≤ 10^9 (0 ≤ i < )
1 ≤ i ≤ 10^5 (0 ≤ i < )
Output Format
Output an integer, the minimum height of the ladder required. If no ladder is required, output 0
Sample Input 0
3 5
15 11 17
5 1 2
Sample Output 0
12
Explanation 0
Arthur's height is 
To hang the first poster, Arthur need to reach a height of , so he needs a ladder of height 9. 
To hang the second poster, Arthur need to reach a height of , so he needs a ladder of height 6. 
To hang the third poster, Arthur need to reach a height of , so he needs a ladder of height 12. 
So, the height of the ladder required is 12.

Sample Input 1
2 5
5 5
4 4
Sample Output 1
0
Explanation 1
Arthur's height is 
To hang both the posters, Arthur need to reach a height of , which he can do without using any ladder 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

float getPosterPoint(long long int a,long long int b){
    return (float)(a-((float) b/4));
}//getPostePoint

long long int getMax(long long int x,long long int y){
    return x>y?x:y;
}//getMax

int main(){
    int size,height;
    scanf("%d%d",&size,&height);
    long long int wallpoints[size],lengths[size];
    
    for(int i=0;i<size;i++)
        scanf("%lld",&wallpoints[i]);
        
    for(int i=0;i<size;i++)
        scanf("%lld",&lengths[i]);
        
    long long int max=INT_MIN;
    for(int i=0;i<size;i++){
        long long int reach_heights=ceil(getPosterPoint(wallpoints[i],lengths[i]) - height);
        max = getMax(reach_heights,max);
    }
    printf("%lld\n",max);
    return 0;
}
/*
Input : 
10 27
157 140 44 83 108 63 137 40 121 106
24 30 17 37 12 34 25 22 35 30
Output :
124
      

*/
