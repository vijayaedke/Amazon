/*
Binary Tree to Binary Search Tree Conversion
Given a Binary Tree, convert it to a Binary Search Tree. The conversion must be done in such a way that keeps the original structure of Binary Tree.
Examples.

Example 1
Input:
          10
         /  \
        2    7
       / \
      8   4
Output:
          8
         /  \
        4    10
       / \
      2   7


Example 2
Input:
          10
         /  \
        30   15
       /      \
      20       5
Output:
          15
         /  \
       10    20
       /      \
      5        30

*/

#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

struct tree {
  int data;
  struct tree *left,*right;
};

int cmp(const void* a, const void *b){
    return *(int *)a - *(int *)b;
}

struct tree *createNode(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void inorderTraversal(struct tree *root, int *array, int *index){
    if(!root)
        return;
    
    inorderTraversal(root->left, array, index);
    array[(*index)++] = root->data;
    printf("%d\t", root->data);
    inorderTraversal(root->right, array, index);
}

void BST(struct tree *root, int *array, int *index){
    if(!root)
        return;
    
    BST(root->left, array, index);
    root->data = array[(*index)++];
    BST(root->right, array, index);
}

struct tree *binaryTreeToBST(struct tree *root){
    if(!root || (!root->left && !root->right))
        return root;
    
    int *array = (int *)malloc(sizeof(int) * 50);
    int index=0;
    
    inorderTraversal(root, array, &index);
    qsort(array, index, sizeof(int), cmp);
    index=0;
    
    BST(root,array,&index);
    printf("\n");
    index=0;
    
    inorderTraversal(root, array, &index);
    
    return root;
}


int main() {
	//code
	struct tree *root = createNode(10);
	root->left = createNode(30);
	root->right = createNode(15);
	
	root->left->left = createNode(20);
	root->right->right = createNode(5);
	
	
	binaryTreeToBST(root);
	return 0;
}
