Given a Binary tree, the problem is to find the mirror of a given node. The mirror of a node is a node which exists at the mirror position of the node in opposite subtree at the root.

Examples:
mirror_nodes
          1
        /   \
       2     3
     /      /  \
    4      5     6
    \     /  \
      7  8    9
In above tree-
Node 2 and 3 are mirror nodes
Node 4 and 6 are mirror nodes.


#include <stdio.h>
#include <stdlib.h>

struct  tree{
    int data;
    struct tree *right, *left;
};

struct tree *create(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}//create

int util(struct tree *left_subtree, struct tree *right_subtree, int key){
    printf("\nLeft = %d Right = %d", left_subtree->data, right_subtree->data);
    if(left_subtree==NULL || right_subtree==NULL)
        return -1;
    
    if(left_subtree->data == key){
        printf("\nLeft subtree Left = %d Right = %d", left_subtree->data, right_subtree->data);
        return right_subtree->data;
    }
    
    if(right_subtree->data == key){
        printf("\nRight subtree Left = %d Right = %d", left_subtree->data, right_subtree->data);
        return left_subtree->data;
    }
    
    return util(left_subtree->left, right_subtree->right, key);
}//util

int mirror(struct tree *root, int key){
    if(root==NULL)
        return -1;
    
    if(!root->left && !root->right){
        if (key==root->data){
            return root->data;
        }
        return -1;
    }
    
    return util(root->left, root->right, key);    
        
}//mirror

int main() {
	//code
	struct tree *root = create(1);
	root->left = create(2);
	root->right = create(3);
	
	root->left->left = create(4);
	root->left->left->right= create(7);
	
	root->right->left = create(5);
	root->right->right = create(6);
	
	root->right->left->left = create(8);
	root->right->left->right = create(9);
	int key = 2;
	
	int mirror_node = mirror(root, key);
	if(mirror_node)
	    printf("\nMirror %d is %d", key, mirror_node);
	return 0;
}

/*output
1.
Left = 2 Right = 3
Left subtree Left = 2 Right = 3
Mirror 2 is 3

2.
Left = 2 Right = 3
Left = 4 Right = 6
Right subtree Left = 4 Right = 6
Mrirror 6 is 4


*/
