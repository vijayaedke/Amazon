/*
Job Sequencing Problem 
Medium Accuracy: 48.94% Submissions: 12133 Points: 4
Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.


Example 1:

Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:
2 60
Explanation:
2 jobs can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an Integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 100000
1 <= Deadline <= 100
1 <= Profit <= 500
*/
#include <stdio.h>
#include <stdlib.h>
#define size 5
struct scheduler{
    int jobid, deadline, profit;
};

int max(int a, int b){
    return a>b?a:b;
}

int  findMaxProfit(struct scheduler *jobs, int n){
    int maxLen=0;
    
    for(int i=0;i<n;i++){
        maxLen = max(jobs[i].deadline, maxLen); 
    }//for
    
    int *array = (int *)malloc(sizeof(int)*(maxLen+1));
    for(int i=0;i<=maxLen;i++){
        array[i] = 0;
    }
    
    for(int i=0;i<n;i++){
        int index = jobs[i].deadline;
        if(array[index]>0){
            while(index>0  && array[index]>0){
                array[index] = max(array[index], jobs[i].profit);
                index--;
            }  
        }//if
        else
            array[index] = jobs[i].profit;
    }//for i
    
    int maxprofit=0, countjobs=0;
    for(int i=0;i<=maxLen;i++){
       if(array[i]){
           maxprofit += array[i];
           countjobs++;
       }
    }
    printf("Jobs executed %d , ", countjobs);
    return maxprofit;
}

int main() {
	//code
    // struct scheduler jobs[size]= {
    //   {1,4,20},
    //   {2,1,10},
    //   {3,1,40},
    //   {4,1,30}  
    // };
    
    struct scheduler jobs[size]={
      {1,2,100},
      {2,1,19},
      {3,2,27},
      {4,1,25},
      {5,1,15}  
    };
    
    printf("Max profit %d\n", findMaxProfit(jobs, size));

	return 0;
}

/*
Jobs executed 2 , Max profit 127
*/
