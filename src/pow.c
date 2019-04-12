Implement pow(x, n), which calculates x raised to the power n (xn).


#include<stdio.h>
#include<math.h>
#include<limits.h>


double myPow(double x, int n) {
    //check for x=1 , any power to 1 is always 1
    if(x==1 && (n<=INT_MIN || n>=INT_MAX))
        return 1;
    
    //check for negative x with power to range of INT_MIN -2147483648
    if(x<=0.00001 && n<=INT_MIN){
        return -x;
    }
    
    //check for negative x with power to range of INT_MAX 2147483647
    if(x<=0.00001 && n>=INT_MAX){
        return x;
    }
    
    //check if the power raise to 'n' is out of integer range
     if(n<=INT_MIN || n>=INT_MAX)
         return 0;
       
    double result=1;
    int power=n,neg=0,x_neg=0;
    if(n<0){
        n=-n;
        neg=1;
    }
    if(x<=0.000001){
        x=-x;
        x_neg=1;
        
    }
    //result=pow(x,n);
    //without using pow function of c library
    for(int i=0;i<n;i++){
         result=result*x;
     }
    //if x is negative check the power number for sign, if odd the resultant number is negative else positive
    if(x_neg && n%2==1){
        result=-result;
    }
    
    //if the power is negative then 1/result
    if(neg){
        result=1/result;
    }
    
    
    return (double) result;
}

int main() {
   double x;
   int n;
   
   scanf("%lf%d",&x,&n);
   printf("%lf",myPow(x,n));
   
   return 0;

}

/*
Inputs - 
-1.00000
2147483647
output - 
-1.000000
Input -
2.00000
10
Output-
1024.00000
Input- 
2.00000
-2
Output -
0.25000
*/
