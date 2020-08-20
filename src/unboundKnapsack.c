#include <stdio.h>
#include <stdlib.h>

// int findProfit(int *weights, int *profits, int capacity, int curr, int size){
//     if(curr>=size || capacity==0)
//         return 0;
    
//     int p1=0;
//     if(weights[curr] <= capacity){
//         p1 = profits[curr] + findProfit(weights, profits, capacity - weights[curr], curr, size);
//     }//if
    
//     int p2 = findProfit(weights, profits, capacity, curr+1, size);
    
//     return p1>p2?p1:p2;
// }//findProfitd

int findProfit(int *weights, int *profits, int capacity, int size){
    if(capacity==0)
        return 0;
        
    int dp[size][capacity+1];
    for(int i=0;i<size;i++)
        dp[i][0] = 0;
    
    for(int i=1;i<=capacity;i++){
        if(weights[0]<=i)
            dp[0][i] = (profits[0] + dp[0][i-1]) > dp[0][i-1] ? (profits[0] + dp[0][i-1]) : dp[0][i-1];
    }//for
    
    
    for(int j=1;j<size;j++){
        for(int i=1;i<=capacity;i++){
            if(weights[j]<=i)
                dp[j][i] = (profits[j] + dp[j][i-weights[j]]) > dp[j-1][i] ? (profits[j] + dp[j][i-weights[j]]) : dp[j-1][i];
            else
                dp[j][i] = dp[j-1][i];
        }//for
    }//for
    
    for(int j=0;j<size;j++){
        for(int i=0;i<=capacity;i++){
            printf("%d\t",dp[j][i]);
        }//for
            printf("\n");
    }//for
    
    return dp[size-1][capacity];
}//findProfit

int main() {
	int weights[] = {1, 3, 4, 5};
	int profits[] = {15, 50, 60, 90};
	int size = sizeof(weights)/sizeof(weights[0]);
	int capacity=5;
	printf("Max profit = %d", findProfit(weights, profits, capacity, size));
	return 0;
}
