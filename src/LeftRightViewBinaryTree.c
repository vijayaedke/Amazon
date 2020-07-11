/*
Print Left View of a Binary Tree
Given a Binary Tree, print left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from left side.

Input : 
                 1
               /   \
              2     3
             / \     \
            4   5     6             
Output : 1 2 4

Input :
        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Output :1 2 4 5 6
*/


/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
#define MAX 100
int levels[MAX];
int res[MAX];


int height(struct TreeNode *root){
    // int l_height, r_height;
    if(root==NULL)
        return 0;
    
    int l_height=height(root->left)+1;
    int r_height=height(root->right)+1;
        
    return l_height < r_height ? l_height : r_height;
    
}//height

void rightView(struct TreeNode *root, int curr_level){
    if(!root)
        return;
    // printf("\nCurrent level = %d %d\n", curr_level, levels[curr_level]);
    if(levels[curr_level]==0){
        res[curr_level] = root->val;
        // printf("in here %d\n", res[curr_level]);
        levels[curr_level] = 1;
    }
    rightView(root->right, curr_level+1);
    rightView(root->left, curr_level+1);
    
}//leftView


int* rightSideView(struct TreeNode* root, int* returnSize){
    
    if(!root){
        *returnSize=0;
        return NULL;
    }//if
    
    if(root->left==NULL && root->right==NULL){
        *returnSize = 1;
        res[0] = root->val;
        return res;
    }//if
    
    int maxlevels = height(root)+1;
    rightView(root, 0);
    *returnSize = maxlevels;
    return res;
}//rightSideView


LeftView of a Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree *right, *left;
};

struct queue{
    struct tree **array;
    int front,rear;
    unsigned capacity;
};

struct queue* init(unsigned size){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity=size;
    q->array=(struct tree **)malloc(sizeof(struct tree )*q->capacity);
    q->front=q->rear=-1;
    return q;
}//init

struct tree *create(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data= data;
    node->right = node->left = NULL;
    return node;
}//create

void enQueue(struct queue *q,struct tree *node){
    if(q->rear==q->capacity-1)
        return;
    if(q->front==-1 && q->rear==-1){
        q->front++;
        q->array[++q->rear]=node;
    }//if
    else{
        q->array[++q->rear]=node;
    }//else
    // printf("\nEnQueued = %d", (q->array[q->rear])->data);
}//enQueue

struct tree* deQueue(struct queue *q){
    if(q->front==-1)
        return NULL;
    struct tree *node;
    if(q->front==q->rear){
        node=q->array[q->front];
        q->front=q->rear=-1;
    }
    else{
        node=q->array[q->front++];
    }
    return node;
}//deQueue

int isEmpty(struct queue *q){
    return q->front==-1;
}//isEmpty

int height(struct tree *root){
    // int l_height, r_height;
    if(root==NULL)
        return 0;
    
    int l_height=height(root->left)+1;
    int r_height=height(root->right)+1;
        
    return l_height < r_height ? l_height : r_height;
    
}//height

void leftView(struct tree *root){
    int size = height(root);
    struct queue *q = init(100);
    int level[size];
    enQueue(q, root);
    enQueue(q, create(-1));
    
    int leftView=0;
    while(!isEmpty(q)){
        struct tree *node = deQueue(q);
        if(node->data!=-1){

            if(!leftView){
                printf("%d\t", node->data);
                leftView=1;
            }
            
            if(node->left)
                enQueue(q, node->left);

            if(node->right)
                enQueue(q, node->right);

        }//if
        else if(node->data==-1 && !isEmpty(q)){
            leftView=0;
            enQueue(q, create(-1));
        }//else
    }//while
}//leftView

int main() {
// 	struct tree *root=create(5);
// 	root->left = create(10);
// 	root->right = create(7);

// 	root->left->left = create(3);
// 	root->right->right = create(14);
// 	root->right->right->left = create(2);
	
	struct tree *root=create(1);
	root->left = create(2);
	root->right = create(3);

	root->left->left = create(4);
	root->left->right = create(5);

	root->right->left = create(6);
	root->right->right = create(7);

	leftView(root);
	return 0;
}

output: - 
Input :        1
             /   \
            2     3
           / \   / \
          4   5 6   7
Output : 1 2 4

Input :         1
              /   \
             2     3
              \   /
               4 5
                  \
                   6
                  / \
                 7   8
Output : 1 2 4 6 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree{
  int data;
  struct tree *left, *right;
};

struct tree *create(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}//create

int height(struct tree *root){
    // int l_height, r_height;
    if(root==NULL)
        return 0;
    
    int l_height=height(root->left)+1;
    int r_height=height(root->right)+1;
        
    return l_height < r_height ? l_height : r_height;
    
}//height

void leftView(struct tree *root, int *levels, int curr_level){
    if(!root)
        return;
    // printf("\nCurrent level = %d %d\n", curr_level, levels[curr_level]);
    if(levels[curr_level]==0){
        printf("%d\t", root->data);
        levels[curr_level] = 1;
    }
    
    leftView(root->left, levels, curr_level+1);
    leftView(root->right, levels, curr_level+1);
    
}//leftView

int main() {
    struct tree* root = create(12); 
    root->left = create(10); 
    root->right = create(30); 
    root->right->left = create(25); 
    root->right->right = create(40); 
// 	struct tree *root = create(10);
// 	root->left = create(20);
// 	root->right = create(30);
	
// 	root->left->left = create(40);

    int maxlevels = height(root);
    int *levels = (int *)malloc(sizeof(int) * maxlevels);
    
    for(int i=0; i<=maxlevels; i++)
        levels[i] = 0;

    leftView(root, levels, 0);
	return 0;
}


/*
output:
12	10	25	

*/
