#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a>b?a:b;
}//max

int findMinJump(int *array, int size){

    if(size==0)
        return 0;
        
    if(size==1)
        return array[0]>0?1:0;

    int reachable = 0, count=0;
    int i = 0;
    while(i<size){
        if(reachable<i)
            return 0;
        else if((i+array[i]) > reachable){
            printf("%d %d %d \n", array[i], reachable, count);
            reachable = i+array[i];
            count++;

            if(reachable>=size-1)
                return count;
        }
        i++;
    }//for
    return count;
}//findMinJump

int main() {
	//code
// 	int array[]={1, 4, 3, 2, 6, 7};
    // int array[]={1, 1, 2, 5, 2, 1, 0, 0, 1, 3};
    int array[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int size = sizeof(array)/sizeof(array[0]);
    printf("Jumps = %d", findMinJump(array, size));
	return 0;
}
