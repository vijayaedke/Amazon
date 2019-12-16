/*
Print a Binary Tree in Vertical Order | Set 2 (Map based Method)
Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
           1
        /    \ 
       2      3
      / \   /   \
     4   5  6   7
               /  \ 
              8   9 
               
              
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9

*/

#include <stdio.h>
#include <stdlib.h>

struct tree {
  int data;
  struct tree *left, *right;
};

struct tree *create(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->right=node->left=NULL;
    return node;
}//create

void printVerticalOrder(struct tree *root, int hd, unsigned *hash){
    if(root==NULL)
        return;
    
    hash[hd] = root->data;
    printf("hash[%d] = %d\n ", hd, hash[hd]);
    
    if(root->left)
        printVerticalOrder(root->left, hd-1, hash);
    
    if(root->right)
        printVerticalOrder(root->right, hd+1, hash);
    
}//printVerticalOrder

int main() {
    struct tree *root=create(1);
    root->left=create(2);
    root->right=create(3);
    
    root->left->left=create(4);
    root->left->right=create(5);
    
    root->right->left=create(6);
    root->right->right=create(7);
    
    root->right->right->left=create(8);
    root->right->right->right=create(9);
    
    int hd=0;
    unsigned array[100];    
    printVerticalOrder(root, hd,array);

	//code
	return 0;
}

/*
output:

hash[0] = 1
 hash[-1] = 2
 hash[-2] = 4
 hash[0] = 5
 hash[1] = 3
 hash[0] = 6
 hash[2] = 7
 hash[1] = 8
 hash[3] = 9

*/
