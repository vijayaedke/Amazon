/*
Find height of a special binary tree whose leaf nodes are connected
Given a special binary tree whose leaf nodes are connected to form a circular doubly linked list, find its height.

For example,


          1 
        /   \ 
       2     3 
     /  \ 
    4    5
   /   
  6 
In the above binary tree, 6, 5 and 3 are leaf nodes and they form a circular doubly linked list. Here, the left pointer of leaf 
node will act as a previous pointer of circular doubly linked list and its right pointer will act as next pointer of circular doubly
linked list.

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
}//createNode

int leaf(struct tree *root){
    return (root->left && root->left->right==root) ||  (root->right && root->right->left==root);
}

int height(struct tree *root){
    if(!root)
        return 0;
        
    if(leaf(root))
        return 0;
    
    int l = height(root->left)+1;
    int r = height(root->right)+1;
    
    return l>r?l:r;
}

int main() {
	//code
	struct tree *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	
    root->left->left->right = createNode(6);
    
    root->left->right->right = root->right;
    root->right->left = root->left->right;
    
    root->left->left->right->right =  root->left->right;
    root->left->right->left = root->left->left->right;
    
    printf("\nheight = %d", height(root)+1);
        
	return 0;
}

/*
output : 
Found
height = 4
*/
