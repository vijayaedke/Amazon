/*
Extract Leaves of a Binary Tree in a Doubly Linked List
Given a Binary Tree, extract all leaves of it in a Doubly Linked List (DLL). Note that the DLL need to be created in-place. 
Assume that the node structure of DLL and Binary Tree is same, only the meaning of left and right pointers are different. 
In DLL, left means previous pointer and right means next pointer.

Let the following be input binary tree
        1
     /     \
    2       3
   / \       \
  4   5       6
 / \         / \
7   8       9   10


Output:
Doubly Linked List
785910

Modified Tree:
        1
     /     \
    2       3
   /         \
  4           6

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct tree* extract(struct tree *root, struct tree **head, struct tree **p){
    if(!root)
        return NULL;
    if(!root->left && !root->right){
        if(*head == NULL){
            *head = root;
            *p = *head;
        }
        else{
            (*p)->right = root;
            root->left = (*p);
            (*p) = root; 
        }
        return NULL;
    }
    
    root->left = extract(root->left, head, p);
    root->right = extract(root->right, head, p);
}//extract

void inorder(struct tree *root){
    if(!root)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void printDLL(struct tree *root){
    if(!root)
        return;
    printf("\n");
    while(root){
        printf("%d\t", root->data);
        root=root->right;
    }
}//printDLL

int main() {
	//code
	struct tree *root = create(1);
	root->left = create(2);
	root->right = create(3);
	
	root->left->left = create(4);
	root->left->right = create(5);
	
	root->right->right = create(6);
	
	root->left->left->left = create(7);
	root->left->left->right = create(8);

	root->right->right->left = create(9);
	root->right->right->right = create(10);
	
	struct tree *head=NULL, *p;
	p = head;
	extract(root, &head, &p);
	inorder(root);
	printDLL(head);
	
	return 0;
}

/*
output:
4	2	1	3	6	
7	8	5	9	10	

*/
