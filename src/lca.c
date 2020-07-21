/*
Lowest Common Ancestor in a Binary Tree | Set 1
Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to find the least common ancestor.
Following is definition of LCA from Wikipedia:
Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants 
(where we allow a node to be a descendant of itself).

The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. Computation of lowest common ancestors may be useful, 
for instance, as part of a procedure for determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance 
from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor.

lca
*/

#include <stdio.h>
#include<stdlib.h>

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

struct tree *lca(struct tree *root, struct tree *n1, struct tree *n2){
    if(!root || !n1 || !n2)
        return NULL;
    
    if(root->data == n1->data || root->data == n2->data)
        return root;
    struct tree *l = lca(root->left, n1, n2);
    struct tree *r = lca(root->right, n1, n2);
    
    return (l && r)?root : (l?l:r);
}//lca

int main() {
	//code
	struct tree *root = createNode(3);
	root->left = createNode(6);
	root->right = createNode(8);
	
	root->left->left = createNode(2);
	root->left->right = createNode(11);
	
    root->left->right->left = createNode(9);
    root->left->right->right = createNode(5);

	root->right->right = createNode(13);
	root->right->right->left = createNode(7);


    struct tree *res = lca(root, root->left->left , root->left->right->right);
    if(res)
        printf("\nRes = %d", res->data);
    
	return 0;
}

/*output :
Res = 6
*/
