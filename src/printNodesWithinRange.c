/*
Count BST nodes that lie in a given range
Given a Binary Search Tree (BST) and a range, count number of nodes that lie in the given range.
Examples:

Input:
        10
      /    \
    5       50
   /       /  \
 1       40   100
Range: [5, 45]

Output:  3
There are three nodes in range, 5, 10 and 40

*/

#include <stdio.h>
#include<stdlib.h>

struct tree {
    int data;
    struct tree *right, *left;
};

struct tree *createNode(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}//createNode

int printNodesWithinRange(struct tree *root, int start, int end, int count){
    if(root==NULL)
        return 0;
        
    if(root->data>=start && root->data<=end){
        printf("%d\t", root->data);
    }
    
        count=1+printNodesWithinRange(root->left, start, end, count);
        count=1+printNodesWithinRange(root->right, start, end, count);
        
   return count;     
}//printNodesWithinRange

int main() {
    
    struct tree *root=createNode(10);
    root->left=createNode(5);
    root->right=createNode(50);
    
    root->left->left=createNode(1);
    
    root->right->left=createNode(40);
    root->right->right=createNode(100);
    
    int start=5, end=45;
    
    printf("Count = %d\n",printNodesWithinRange(root, start, end, 0));

	return 0;
}

/*
output:
10	5	40	Count = 3


*/
