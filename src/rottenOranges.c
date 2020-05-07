/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:
Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

#include <stdio.h>
#include <stdlib.h>

struct pair{
    int x,y;
    int time;
};

struct queue{
  struct pair **p;
  int front, rear;
  unsigned capacity;
};

struct pair *getPair(int i, int j, int time){
    struct pair *p = (struct pair *)malloc(sizeof(struct pair));
    p->x=i;
    p->y=j;
    p->time=time;
    return p;
}//getPair

struct queue *create(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->p = (struct pair **)malloc(sizeof(struct pair *)*q->capacity);
    q->front=q->rear=-1;
    return q;
}//create

int isEmpty(struct queue *q){
    return q->front==-1;
}//isEmpty

int isFull(struct queue *q){
    return q->rear==q->capacity-1;
}//isFull

void enQueue(struct queue *q, struct pair *node){
    if(isFull(q))
        return;
    
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->p[++q->rear] = node;
    }
    else{
        q->p[++q->rear] = node;
    }
    printf("\nEnqueued = %d %d\n", (q->p[q->rear])->x, (q->p[q->rear])->y); 
}//enQueue

struct pair *deQueue(struct queue *q){
    if(isEmpty(q))
        return NULL;
    struct pair *x;
    if(q->front==q->rear){
        x = q->p[q->front];
        q->front=q->rear=-1;
    }//if
    else{
        x = q->p[q->front++];
    }//else
    return x;
}//deQueue

int isSafe(int **grid, int i, int j, int rows, int cols){
    // printf("\ni j %d %d\n", i, j);
    return (i>=0 && i<rows) && (j>=0 && j<cols) && grid[i][j]==1;
}

void fillArray(struct queue *q, int **grid, struct pair *node, int rows, int cols){
    int i=node->x;
    int j=node->y;
    struct pair *newnode;
    
    if(isSafe(grid, i+1, j, rows, cols)){
        // printf("Down %d %d\n", i+1, j);
        grid[i+1][j]=2;
        newnode = getPair(i+1, j, node->time +1);
        enQueue(q, newnode);
    }
    if(isSafe(grid, i-1, j, rows, cols)){
        // printf("Up %d %d\n", i-1, j);
        grid[i-1][j]=2;
        newnode = getPair(i-1, j, node->time +1);
        enQueue(q, newnode);
    }
    if(isSafe(grid, i, j+1, rows, cols)){
        // printf("Right %d %d\n", i, j+1);
        grid[i][j+1]=2;
        newnode = getPair(i, j+1, node->time +1);
        enQueue(q, newnode);
    }
    if(isSafe(grid, i, j-1, rows, cols)){
        // printf("Left %d %d\n", i, j-1);
        grid[i][j-1]=2;
        newnode = getPair(i, j-1, node->time +1);
        enQueue(q, newnode);
    }
}//fillArray

int checkArray(int **grid, int rows, int cols){
    printf("\n%d %d\n", rows, cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<(cols);j++){
            printf("%d\t", grid[i][j]);
            if(grid[i][j]==1)
                return 0;
        }//for j
        printf("\n");
    }//for i
    
    return 1;
}//checkArray

int orangesRotting(int** grid, int r, int* c){
    int rows=r, cols=*c;
    struct queue *q = create(rows*(cols));
    struct pair *node;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<(cols);j++){
            // printf("%d\t", grid[i][j]);
            if(grid[i][j]==2){
                node = getPair(i,j,0);
                enQueue(q,node);
            }                
        }//for j
        // printf("\n");
    }//for i
    
    int count=0;
    while(!isEmpty(q)){
        struct pair *p = deQueue(q);
        printf("\nP %d %d\n", p->x, p->y);
        fillArray(q, grid, p, rows, cols);
        count=p->time;
    }//while
    
    
    return checkArray(grid, rows, cols) == 1?count : -1;
}

int main() {
	//code
	int rows=3, cols=3;
    int **array = (int **)malloc(sizeof(int *)*rows);
    for(int i=0;i<rows;i++)
        array[i] = (int *)malloc(sizeof(int) * cols);
        
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&array[i][j]);
        }//for j
    }//for i
    
	printf("\ntime taken %d", orangesRotting(array, rows, &cols));
	
	return 0;
}

/*
input : 
2 1 1 1 1 0 0 1 1

Output :

Enqueued = 0 0

P 0 0

Enqueued = 1 0

Enqueued = 0 1

P 1 0

Enqueued = 1 1

P 0 1

Enqueued = 0 2

P 1 1

Enqueued = 2 1

P 0 2

P 2 1

Enqueued = 2 2

P 2 2

3 3
2	2	2	
2	2	0	
0	2	2	

time taken 4
*/
