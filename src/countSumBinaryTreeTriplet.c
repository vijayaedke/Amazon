/*
Count all Grandparent-Parent-Child Triplets in a binary tree whose sum is greater than X

Given an integer X and a binary tree, the task is to count the number of triplet triplets of 
nodes such that their sum is greater than X and they have a grandparent -> parent -> child relationship.

Input: X = 100

               10
         /           \
       1              22
    /    \          /    \
  35      4       15       67
 /  \    /  \    /  \     /  \
57  38  9   10  110 312  131 414
                    /          \
                   8            39
Output: 6
The triplets are:
22 -> 15 -> 110
22 -> 15 -> 312
15 -> 312 -> 8
22 -> 67 -> 131
22 -> 67 -> 414
67 -> 414 -> 39


*/

#include <stdio.h>
#include <stdlib.h>

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

void countTriplets(struct tree *grandparent, struct tree *parent, struct tree *child,int *count, int x){
    if( grandparent && parent && child && ((grandparent->data + parent->data + child->data) > x)){
        printf("\n%d %d %d", grandparent->data, parent->data, child->data);
        (*count)+=1;
    }
    if(!child)
        return;
    countTriplets(parent, child, child->left,count, x);
    countTriplets(parent, child, child->right, count, x);
    
}//countTriplets

int main() {
	//code
	struct tree *root = create(10);
	root->left = create(1);
    root->right = create(22) ;
  
    root->left->left = create(35) ;
    root->left->right = create(4) ;
  
    root->right->left = create(15);
    root->right->right = create(67); 
  
    root->left->left->left = create(57); 
    root->left->left->right = create(38); 
  
    root->left->right->left = create(9);
    root->left->right->right = create(10); 
  
    root->right->left->left = create(110);
    root->right->left->right = create(312); 
  
    root->right->right->left = create(131);
    root->right->right->right = create(414); 
  
    root->right->left->right->left = create(8); 
  
    root->right->right->right->right = create(39); 
  
    int count=0;
    countTriplets(NULL, NULL, root, &count, 100);
    printf("\nCount %d", count);
	
	return 0;
}
/*
output:
22 15 110
22 15 312
15 312 8
22 67 131
22 67 414
67 414 39
Count 6

*/
