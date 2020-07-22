/*
Find Minimum Depth of a Binary Tree
Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to 
the nearest leaf node.

For example, minimum height of below Binary Tree is 2.
   10
  /    
5  

*/
#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

struct tree {
  int data;
  struct tree *left,*right;
};

struct tree *createNode(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int util(struct tree *root){
    if(!root)
        return 0;
    
    int left = util(root->left);
    int right = util(root->right);
    
    if(left<right)
        return (left==0)?right+1:left+1;
    return (right==0)?left+1:right+1;
}

int minDepth(struct tree *root){
    if(!root)
        return 0;
    
    if(!root->left && !root->right)
        return 0;
    return util(root);
}

int main() {
	//code
	struct tree *root = createNode(3);
	root->left = createNode(9);
	root->right = createNode(20);
	
// 	root->left->left = createNode(1);
// 	root->left->left->left = createNode(5);
// 	root->left->left->right = createNode(1);
	
	root->right->left = createNode(15);
	root->right->right = createNode(7);
	
// 	root->right->left->right = createNode(6);
// 	root->right->right->right = createNode(8);
	
	int max = minDepth(root);
	printf("%d\t", max);
	return 0;
}
