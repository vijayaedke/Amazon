/*
Difference between sums of odd level and even level nodes of a Binary Tree
Given a a Binary Tree, find the difference between the sum of nodes at odd level and the sum of nodes at even level. Consider root as level 1, left and right children of root as level 2 and so on.
For example, in the following tree, sum of nodes at odd level is (5 + 1 + 4 + 8) which is 18. And sum of nodes at even level is (2 + 6 + 3 + 7 + 9) which is 27. The output for following tree should be 18 – 27 which is -9.

      5
    /   \
   2     6
 /  \     \  
1    4     8
    /     / \ 
   3     7   9  
   
   
Algorithm:
1. Traverse tree in level order traversal.
2. Check if the level is even or odd.
3. Return the difference between odd and even sum of level order traversal.

*/

#include<stdio.h>
#include<stdlib.h>

struct tree {
  int data;
  struct tree *left, *right;
};

struct queue{
  int front, rear;
  struct tree **array;
  unsigned capacity;
  int count;
};


struct tree *createNode(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}//createNode

struct queue *init(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->array = (struct tree **)malloc(sizeof(struct tree) * q->capacity);
    q->front=q->rear=-1;
    q->count=0;
    return q;
}//init

int isFull(struct queue *q){
    return q->capacity-1==q->rear;
}//isFull

int isEmpty(struct queue *q){
    return q->front==-1;
}//isEmpty

void enQueue(struct queue *q, struct tree *t){
    if(isFull(q)){
        printf("\nQueue is full\n");
        return;
    }//isFull
    
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->count++;
        q->array[++q->rear]=t;
        // printf("\nFirst Enqueue  = %d", (q->array[q->rear])->data);
    }//if
    else{
        q->count++;
        q->array[++q->rear]=t;
        // printf("\nEnqueue  = %d", (q->array[q->rear])->data);
    }//else
}//enQueue

struct tree *deQueue(struct queue *q){
    if(isEmpty(q))
        return NULL;
    struct tree *t=NULL;
    if(q->front==q->rear){
        // printf("\nOnly one element\n");
        t=q->array[q->front++];
        q->front=q->rear=-1;
        q->count=0;
    }//if
    else{
        t=q->array[q->front++];
        q->count--;
    }//else
    return t;
}//deQueue

int getCount(struct tree *root, int count){
    if(root==NULL)
        return 0;
    else{    
    if(root->left)
        count=1+getCount(root->left, count);
    if(root->right)
        count=1+getCount(root->right, count);
    return count;
    }//else
}//getCount

void traversal(struct tree *root){
    int count = getCount(root, 0);
    // printf("\nNumber of nodes = %d\n", count+1);
    struct queue *q=init(count+1);
    struct tree *node=root;
    enQueue(q, node);
    int level=0, even_sum=0, odd_sum=0;
    
    while(!isEmpty(q)){
          level+=1;
          int size=q->count;
          printf("\nlevel %d => ", level);

          while(size>0){
               node = deQueue(q);
               printf("\t %d", node->data);
               
               if(level%2==0)
                    even_sum+=node->data;
               else
                    odd_sum+=node->data;
               
               if(node->left){
                   enQueue(q, node->left);
               }
               if(node->right){
                   enQueue(q, node->right);
               }
               size--;       
           
          }//while
        
    }//while
    
    printf("\nDifference %d - %d  = %d", odd_sum, even_sum, (odd_sum - even_sum));
}//traversal

int main() {
    
    struct tree *root = createNode(5); 
    root->left = createNode(2); 
    root->right = createNode(6); 
    root->left->left = createNode(1); 
    root->left->right = createNode(4); 
    root->left->right->left = createNode(3); 
    root->right->right = createNode(8); 
    root->right->right->right = createNode(9); 
    root->right->right->left = createNode(7); 
  
    traversal(root);

    return 0;
}

/*
Output

level 1 => 	 5
level 2 => 	 2	 6
level 3 => 	 1	 4	 8
level 4 => 	 3	 7	 9
Difference 18 - 27  = -9

*/


