/*
Sliding Window Maximum (Maximum of all subarrays of size k)
Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
Examples :

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3
Output: 3 3 4 5 5 5 6


*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct queue{
  int *data;
  unsigned capacity;
  int rear, front;
};

struct queue *init(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->data = (int *)malloc(sizeof(int) * q->capacity);
    q->front=q->rear=-1;
    q->data[q->rear]=-1;
    return q;
}//init

int isEmpty(struct queue *q){
    return q->front==-1;
}//isEmpty

int isFull(struct queue *q){
    return q->rear==q->capacity-1;
}//isFull

void enQueue(struct queue *q, int value){
    if(isFull(q))
        return;
    if(q->rear==-1 && q->front==-1){
        q->front++;
        q->data[++q->rear] = value;
        // printf("\nEnqueued %d", q->data[q->rear]);
    }//if
    else{
        q->data[++q->rear] = value;
        // printf("\nEnqueued %d", q->data[q->rear]);
    }//else
}//enQueue

int deQueue(struct queue *q){
    if(isEmpty(q))
        return -1;
    int value;
    if(q->front==q->rear){
        value = q->data[q->front--];
        q->rear=-1;
        // printf("\nDequeued %d", value);
    }//if
    else{
        value = q->data[q->front--];
        // printf("\nDequeued %d", value);
    }//else

    return value;
}//deQueue

int deQueueFromRear(struct queue *q){
    if(isEmpty(q))
        return -1;
    int value;
    value= q->data[q->rear--];
    //     // printf("\nDequeued %d", value);
    // // }//else
    return value;
}//deQueueFromRear

int printMax(int *array, int size, int k, int index, struct queue *q){
    int start_index = index;
    // printf("%d %d %d\n\n", array[q->data[q->rear]], array[index], q->rear);
    if(array[q->data[q->rear]] < array[index]){
        deQueue(q);
    }//while
    
    if((index-k) < (q->data[q->rear])){
        deQueueFromRear(q);
    }
    else{
        enQueue(q, index);
    }
    // printf("front = %d, rear = %d\n", array[q->data[q->front]], array[q->data[q->rear]]);
    return array[q->data[q->front]];
    
}//printMax

int main() {
    int array[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int size = sizeof(array)/sizeof(array[0]);
    int k = 3;
    struct queue *q = init(size);
    // enQueue(q, 10);
    for(int i=0;i<size;i++){
        int max = printMax(array, size, k, i, q);
        if(i>=k-1)
            printf("\nMax = %d\n", max);
    }//for
    return 0;
}
