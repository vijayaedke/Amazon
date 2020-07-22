/*
Longest consecutive sequence in Binary tree
Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order.
Every node is considered as a path of length 1.

Input : 
    1
      \
        3
      /   \
    2       4
             \
              5
Output : 
  Length = 3

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

void longestConsecutiveSequence(struct tree *root, struct tree *parent, int *max, int *lcp){
    if(!root || !parent)
        return;
    
    if(root->data > parent->data && (root->data - parent->data)==1){
        *lcp = *max < *lcp+1 ? *lcp+1 : *max;
        max = lcp;
    }
    longestConsecutiveSequence(root->left, root, max, lcp);
    longestConsecutiveSequence(root->right, root, max, lcp);
}//longestConsecutiveSequence


int main() {
	//code
	struct tree *root = createNode(1);
	root->right = createNode(3);
	root->right->left = createNode(2);
	root->right->right = createNode(4);
	root->right->right->right = createNode(5);
	int max=1, lcp=1;
	longestConsecutiveSequence(root, root, &max, &lcp);
  printf("Length = %d", lcp);
  return 0;
}
