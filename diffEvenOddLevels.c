/*
Difference between sums of odd level and even level nodes of a Binary Tree
Given a a Binary Tree, find the difference between the sum of nodes at odd level and the sum of nodes at even level. Consider root as level 1, left and right children of root as level 2 and so on.
For example, in the following tree, sum of nodes at odd level is (5 + 1 + 4 + 8) which is 18. And sum of nodes at even level is (2 + 6 + 3 + 7 + 9) which is 27. The output for following tree should be 18 – 27 which is -9.

      5
    /   \
   2     6
 /  \     \  
1    4     8
    /     / \ 
   3     7   9  


input 2 :

           3
      /         \
    6            8
 /    \         /   
2     11       13   
     /  \      /    
    9     5   7   
    
output: 6
*/

#include <stdio.h>
#include<stdlib.h>

struct tree {
  char data;
  struct tree *left,*right;
};

struct tree *createNode(char data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int diff(struct tree *root, int level, int *even_level, int *odd_level){
    if(!root)
        return 0;
        
    if(level%2==0)
        (*even_level)+=root->data;
    else
        (*odd_level)+=root->data;
    
    int v=diff(root->left, level+1, even_level, odd_level);
    int y=diff(root->right, level+1, even_level, odd_level);
    
    return ((*odd_level) - (*even_level));
}//diff

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

    int even=0, odd=0;
    int res = diff(root, 0, &even, &odd);
    if(res)
        printf("\nRes = %d", res);
    
	return 0;
}
