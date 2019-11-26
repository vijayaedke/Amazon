#include <stdio.h>
#include <stdlib.h>

int subarray(int *array, int n){
   int hash[100]={0};
   
   int sum=0;
   
   for(int i=0;i<n;i++){
       sum+=array[i];
       if(hash[sum]!=0)
            return 1;
       else
            hash[sum]=sum;
   }//for
   return 0;
}//subarray

int main() {
	//code
   // int array[] = { 8,9 };
  int array[] = { 4, 2, -3, -1, 0, 4 };
	int n = sizeof(array)/sizeof(array[0]);
	
	if(subarray(array, n))
	    printf("True");
	else
	    printf("false");
	return 0;
}

/*
output:
True
*/
