/*
Sum of all the numbers that are formed from root to leaf paths
Given a binary tree, where every node value is a Digit from 1-9 .Find the sum of all the numbers which are formed from root to leaf paths.
For example consider the following Binary Tree.

           6
       /      \
     3          5
   /   \          \
  2     5          4  
      /   \
     7     4
  There are 4 leaves, hence 4 root to leaf paths:
   Path                    Number
  6->3->2                   632
  6->3->5->7               6357
  6->3->5->4               6354
  6->5>4                    654   
Answer = 632 + 6357 + 6354 + 654 = 13997 
*/


#include <stdio.h>
#include<stdlib.h>

struct tree{
  int data;
  struct tree *left, *right;
};

struct tree *createNode(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}//createNode

int sumLeafNode(struct tree *root, int val, int *sum){
    if(root==NULL){
        return 0;
    }
    val = (val * 10) + root->data;

    if(root->left==NULL && root->right==NULL){
        printf("Current val = %d\n", val);
        *sum+=val;
        return val ;
    }

    // printf("Current val = %d\n", val);
    sumLeafNode(root->left, val, sum);
    sumLeafNode(root->right, val, sum);
    
    return *sum;
}//sumLeafNode

int main() {
	//code
    struct tree *root=createNode(6);
    root->left=createNode(3);
    root->right=createNode(5);
    
    root->left->left=createNode(2);
    root->left->right=createNode(5);
    
    root->right->right=createNode(4);
    
    root->left->right->left=createNode(7);
    root->left->right->right=createNode(4);
    int sum = 0;
    printf("Sum = %d", sumLeafNode(root, 0, &sum));
    
	return 0;
}

/*ouput 
Current val = 632
Current val = 6357
Current val = 6354
Current val = 654
Sum = 13997

*/
