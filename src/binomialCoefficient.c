/*
Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

Example 2:

Input: n = 2, r = 4
Output: 0
Explaination: r is greater than n.

Your Task:
You do not need to take input or print anything. Your task is to complete the function nCr() which takes n and r as input parameters and returns nCr modulo 109+7..


Expected Time Complexity: O(n*r)
Expected Auxiliary Space: O(r)


Constraints:
1 ≤ n ≤ 1000
1 ≤ r ≤ 800

METHOD 1: (Using Dynamic Programming)
A Simple Solution is to first compute nCr, then compute nCr % p. This solution works fine when the value of nCr is small. 
What if the value of nCr is large? 
The value of nCr%p is generally needed for large values of n when nCr cannot fit in a variable, and causes overflow. So computing nCr and then using modular operator is not a good idea as there will be overflow even for slightly larger values of n and r. For example the methods discussed here and here cause overflow for n = 50 and r = 40.
The idea is to compute nCr using below formula  

   C(n, r) = C(n-1, r-1) + C(n-1, r)
   C(n, 0) = C(n, n) = 1
Working of Above formula and Pascal Triangle: 
Let us see how above formula works for C(4, 3)
1==========>> n = 0, C(0, 0) = 1 
1–1========>> n = 1, C(1, 0) = 1, C(1, 1) = 1 
1–2–1======>> n = 2, C(2, 0) = 1, C(2, 1) = 2, C(2, 2) = 1 
1–3–3–1====>> n = 3, C(3, 0) = 1, C(3, 1) = 3, C(3, 2) = 3, C(3, 3)=1 
1–4–6–4–1==>> n = 4, C(4, 0) = 1, C(4, 1) = 4, C(4, 2) = 6, C(4, 3)=4, C(4, 4)=1 
So here every loop on i, builds i’th row of pascal triangle, using (i-1)th row
*/

#include <stdio.h>
#include <stdlib.h>

int fact(int n){
    
    if(n==1)
        return 1;
    
    return n*fact(n-1);
    
}//fact

int util(int n, int r){
    if(r>n)
        return -1;
    //recursive approach
    // return fact(n)/(fact(r)*fact(n-r));
    
    //dp approach
    int array[n+1][n+1];
	
	array[0][0] = 1;
	for(int i=1;i<=n;i++){
	    if(i>0){
    	    array[i][0] = 1;
    	    array[i][i] = 1;
	    }
	}
	
	for(int i=2;i<=n;i++){
	    for(int j=i-1;j>=1;j--){
	        array[i][j] = array[i-1][j]+array[i-1][j-1];
	    }
	}//for
	
	for(int i=0;i<=n;i++){
	    for(int j=0;j<=i;j++){
	        printf("%d\t", array[i][j]);
	    }
	    printf("\n");
	}
	return array[n][r];
}

int main() {
	//code
	int n=3, r=2;
	printf("%d", util(n, r));
	
	
	return 0;
}

/*
output:
1	
1	1	
1	2	1	
1	3	3	1	

3
*/
