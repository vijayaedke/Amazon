/*
lood fill Algorithm – how to implement fill() in paint?
Last Updated: 19-11-2020
In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is replaced with a new selected color. Following is the problem statement to do this task. 
Given a 2D screen, location of a pixel in the screen and a color, replace color of the given pixel and all adjacent same colored pixels with the given color.

Example: 

Input:
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 2, 2, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 0, 1, 0},
               {1, 1, 1, 2, 2, 2, 2, 0},
               {1, 1, 1, 1, 1, 2, 1, 1},
               {1, 1, 1, 1, 1, 2, 2, 1},
               };
    x = 4, y = 4, newColor = 3
The values in the given 2D screen
  indicate colors of the pixels.
x and y are coordinates of the brush,
   newColor is the color that
should replace the previous color on 
   screen[x][y] and all surrounding
pixels with same color.

Output:
Screen should be changed to following.
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
               {1, 1, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 1, 0, 1, 1},
               {1, 3, 3, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 0, 1, 0},
               {1, 1, 1, 3, 3, 3, 3, 0},
               {1, 1, 1, 1, 1, 3, 1, 1},
               {1, 1, 1, 1, 1, 3, 3, 1},
               };

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 8
#define N 8

struct pair{
    int x,y;
};

struct queue{
    int front, rear;
    struct pair **array;
    unsigned capacity;
};

struct pair *getPair(int x, int y){
    struct pair *p = (struct pair *)malloc(sizeof(struct pair));
    p->x=x;
    p->y=y;
    return p;
}//getPair

struct queue *init(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->array = (struct pair **)malloc(sizeof(struct pair *) * q->capacity);
    q->front = q->rear = -1;
    return q;
}//init

int isEmpty(struct queue *q){
    return q->front==-1;
}//isEmpty

int isFull(struct queue *q){
    return q->rear==q->capacity-1;
}//isFull

void enQueue(struct queue *q, struct pair *p){
    if(isFull(q))
        return;
    
    if(q->front==-1 && q->rear==-1){
        q->array[++q->rear] = p;
        q->front++;
    }
    else
        q->array[++q->rear] = p;
}//push

struct pair *deQueue(struct queue *q){
    if(isEmpty(q))
        return NULL;
    struct pair *p = NULL;    
    if(q->front==q->rear){
        p = q->array[q->front];
        q->front=q->rear=-1;
    }
    else{
        p = q->array[q->front++];
    }
    
    return p;
}//deQueue

void printMatrix(int array[][N]){
     for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            printf("%d\t", array[i][j]);
        }//for j
            printf("\n");
    }//for i
}//printMatrix
//recursive
// void  floodFillMatrix(int array[][N], int start, int end, int temp, int newcolor){
    
//     if(start>M || start <0 || end>N || end<0 || array[start][end]!=temp)
//         return;
    
//     if(array[start][end]==temp)
//         array[start][end] = newcolor;
    
//     floodFillMatrix(array, start+1, end, temp, newcolor);
//     floodFillMatrix(array, start-1, end, temp, newcolor);
//     floodFillMatrix(array, start, end+1, temp, newcolor);
//     floodFillMatrix(array, start, end-1, temp, newcolor);
    
// }//floodFill


void  floodFillMatrix(int array[][N], int start, int end, int temp, int newcolor){
    if(start>M || start <0 || end>N || end<0 || array[start][end]!=temp)
        return;
    
    int visited[M][N];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            visited[i][j] = 0;
        }
    }
    
    
    struct queue *q = init(M*N);
    
    if(array[start][end]==temp){
        enQueue(q, getPair(start, end));
        visited[start][end] = 1;
    }
        
    
    while(!isEmpty(q)){
        struct pair *p = deQueue(q);

        if(visited[p->x][p->y]==0){
            array[p->x][p->y] = newcolor;
            visited[p->x][p->y] = 1;
        }//if
        
        //up
        if(visited[p->x+1][p->y]==0 && array[p->x+1][p->y]==temp)
            enQueue(q, getPair(p->x+1, p->y));
        
        
        //down
        if(visited[p->x-1][p->y]==0 && array[p->x-1][p->y]==temp)
            enQueue(q, getPair(p->x-1, p->y));
        

        //left
        if(visited[p->x][p->y-1]==0 && array[p->x][p->y-1]==temp)
            enQueue(q, getPair(p->x, p->y-1));
        
        
        //right
        if(visited[p->x][p->y+1]==0 && array[p->x][p->y+1]==temp)
            enQueue(q, getPair(p->x, p->y+1));
        
    }//while
    
    printMatrix(array);
}//floorFillMatrix


int main() {
    int array[M][N] = {
       {1, 1, 1, 1, 1, 1, 1, 1},
       {1, 1, 1, 1, 1, 1, 0, 0},
       {1, 0, 0, 1, 1, 0, 1, 1},
       {1, 2, 2, 2, 2, 0, 1, 0},
       {1, 1, 1, 2, 2, 0, 1, 0},
       {1, 1, 1, 2, 2, 2, 2, 0},
       {1, 1, 1, 1, 1, 2, 1, 1},
       {1, 1, 1, 1, 1, 2, 2, 1},
       };

    int start = 4, end = 4, newColor = 3;
    int temp = array[start][end];
    floodFillMatrix(array, start, end, temp, newColor);
    
    // printMatrix(array);

	return 0;
}
