/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Input Tree
       1
      / \
     2   3
    / \   \
   4   5   6


Output Tree
       1--->NULL
      / \
     2-->3-->NULL
    / \   \
   4-->5-->6-->NULL
 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000

*/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct queue{
    struct Node* *array;
    unsigned capacity;
    int front,rear;
};


struct queue* init(unsigned capacity){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->array=(struct Node **)malloc(sizeof(struct Node)*q->capacity);
    q->front=q->rear=-1;
    return q;
}

struct Node *createNode(int data){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->val = data;
    t->left=t->right=t->next=NULL;
    return t;
}


void enQueue(struct Node *node , struct queue *q){
    if(q->rear==(q->capacity-1)){
        // printf("\nQueue is full\n");
        exit(1);
    }
    
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->rear++;
        q->array[q->rear]=node;
    }
    else{
        q->rear++;
        q->array[q->rear]=node;
    }
}

struct Node *deQueue(struct queue *q){
    struct Node *node;
    if(q->front==-1){
        // printf("\nQueue is empty\n");
        exit(1);
    }
    
    if(q->front==q->rear){
        node = q->array[q->front];
        q->front=q->rear=-1;
        return node;
    }
    else{
        node = q->array[q->front];
        q->front++;
        return node;
    }
}//deQueue

int size(struct queue *q){
    return q->rear;
}//size




struct Node* connect(struct Node* root) {
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return root;
    
	struct queue *q = init(10000);
    struct Node *temp=root, *prev=NULL;
    int count=0;
    enQueue(root, q);
    enQueue(createNode(-1001), q);
    while(q->front!=-1){
        struct Node *temp = deQueue(q);
        if(temp->val!=-1001){
            printf("%d\t", temp->val);
            if(prev!=NULL)
                prev->next = temp;
            if(temp->left)
                enQueue(temp->left, q);
            if(temp->right)
                enQueue(temp->right, q);
            
            prev=temp;
        }//if
        else if(q->front!=-1){
            enQueue(createNode(-1001), q);
            printf("\n");
            prev=NULL;
        }//else if
    }//while
    
    return root;
}

/*
input:
[-48,-92,-31,-84,61,-49,-32,82,-53,-56,17,-58,-78,-63,4,-70,65,-77,13,-27,-72,-28,-26,25,94,-6,-37,69,80,81,-47,-84,1,37,100,60,48,14,-44,-29,78,0,-58,-49,67,-22,-9,44,-25,2,93,50,90,-27,-82,-51,-76,26,-5,-79,25,80,-96,18,94,-7,-3,37,58,-76,-1,-1,-57,73,-25,-18,22,11,40,-63,38,-44,12,-62,-6,42,81,-97,26,65,-89,-31,-46,79,-3,1,62,77,-43,55,-63,-38,93,-73,65,-61,-71,-76,28,90,38,83,-3,-99,-60,40,-10,74,-89,34,50,49,-79,6,91,-43,-81]
output:
[-48,#,-92,-31,#,-84,61,-49,-32,#,82,-53,-56,17,-58,-78,-63,4,#,-70,65,-77,13,-27,-72,-28,-26,25,94,-6,-37,69,80,81,-47,#,-84,1,37,100,60,48,14,-44,-29,78,0,-58,-49,67,-22,-9,44,-25,2,93,50,90,-27,-82,-51,-76,26,-5,-79,25,80,-96,#,18,94,-7,-3,37,58,-76,-1,-1,-57,73,-25,-18,22,11,40,-63,38,-44,12,-62,-6,42,81,-97,26,65,-89,-31,-46,79,-3,1,62,77,-43,55,-63,-38,93,-73,65,-61,-71,-76,28,90,38,83,-3,-99,-60,40,-10,74,-89,34,50,49,-79,6,91,-43,-81,#]


input:
[-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13]
output:
[-1,#,0,1,#,2,3,4,5,#,6,7,8,9,10,11,12,13,#]

*/
