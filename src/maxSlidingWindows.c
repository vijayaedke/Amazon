/*
Sliding Window Maximum (Maximum of all subarrays of size k)
Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
Examples :

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5 
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6

Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 
Output: 10 10 10 15 15 90 90
Explanation:
Maximum of first 4 elements is 10, similarly for next 4 
elements (i.e from index 1 to 4) is 10, So the sequence 
generated is 10 10 10 15 15 90 90
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct queue{
  int *data;
  unsigned capacity;
  int front, rear;
};

struct queue *init(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->data = (int *)malloc(sizeof(int) * q->capacity);
    q->front = q->rear =-1;
    return q;
}//init

int isEmpty(struct queue *q){
    return q->front == -1;
}//isEmpty

int isFull(struct queue *q){
    return q->rear == q->capacity-1; 
}//isFull

void enQueueRear(struct queue *q, int val){
    if(isFull(q))
        return;
    
    if(q->front==-1 && q->rear==-1){
        q->data[++q->rear] = val;
        q->front++;
    }
    else{
        q->data[++q->rear] = val;
    }//else
    // printf("\nEnqueue =%d", q->data[q->rear]);
}//enQueueRear

int deQueueFront(struct queue *q){
    if(isEmpty(q))
        return 0;
    int val;
    if(q->front==q->rear){
        val = q->data[q->front];
        q->front = q->rear = -1;
    }//if
    else{
        val = q->data[q->front++];
    }//else
    // printf("\nDeQueue = %d", val);
    return val;
}//deQueueFront

int deQueueRear(struct queue *q){
    if(isEmpty(q))
        return 0;
        
    int val;
    if(q->front==q->rear){
        val = q->data[q->rear];
        q->front = q->rear = -1;
    }//if
    else{
        val = q->data[q->rear--];
    }//else
    // printf("\nDeQueue = %d", val);
    return val;
}//deQueueRear

int peek(struct queue *q){
    return q->data[q->front];
}//peek

void deQueue(int *array, int size, int k){
    struct queue *q = init(size);
    enQueueRear(q, 0);
    
    for(int i=1;i<size;i++){
        int x = abs(k-i); 
        // printf("\nX = %d %d\n", x, peek(q)>x);
        while(!isEmpty(q) && (array[q->data[q->rear]] < array[i]) ){
            deQueueRear(q);
        }//while
        
        while(!isEmpty(q) && (peek(q) <= x)){
            deQueueFront(q);
        }//while
        
        enQueueRear(q, i);
        if(i>=k-1)
            printf("\n%d", array[peek(q)]);
    }//for
    
}//deQueue

int main() {
	//code
	int array[] ={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
	int k=4;
  /*
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int k=3;
  int array[] = { 12, 1, 78, 90, 57, 89, 56 };
	int k=3;
  */
	
	int size = sizeof(array) / sizeof(array[0]);
	deQueue(array, size, k);
	return 0;
}

/*
output:

10
10
10
15
15
90
90
*/
