#include <stdio.h>
#include <stdlib.h>

struct time{
    int start, finish;
};

int cmp(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

void printMaxMeetings(int n, struct time t[n]){
    qsort(t, n, sizeof(struct time), cmp);
    
    int count= t[0].finish - t[0].start;
    printf("%d %d %d %d\n", t[0].start, t[0].finish, count, n-1);

    for(int i=1;i<n;i++){
        if(t[i-1].start > t[i].finish){
            printf("%d %d ", t[i].start, t[i].finish);
            count+=(t[i].finish - t[i].start);
            printf("%d %d\n", count, n-i-1);
        }
    }
}

int main() {
	//code
    // struct time t[6] = {{1,2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    struct time t[8] = { {75250, 112960}, {50074, 114515}, {43659, 81825}, {8931, 93424}, {11273, 54316}, {27545, 35533}, {50879, 73383}, {77924, 160252}};
    // printMaxMeetings(6, t);
    printMaxMeetings(8, t);
	return 0;
}

/*
output:
77924 160252 82328 7
50879 73383 104832 5
27545 35533 112820 2

8 9 1 5
5 7 3 4
3 4 4 2
1 2 5 1

*/
