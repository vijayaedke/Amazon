/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Follow up:

Recursive solution is trivial, could you do it iteratively?

 

Example 1:
 i
| \ \
3 2 4
| \
5 6

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]

Print all leaf nodes of an n-ary tree
Input: edge[][] = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}}
Output: 4 5 6
    1
   / \
  2   3
 / \   \
4   5   6

*/

#include <stdio.h>
#include <stdlib.h>

struct nary{
  int data;
  struct nary *child, *next;
};

struct nary *create(int data){
    struct nary *node = (struct nary *)malloc(sizeof(struct nary));
    node->data = data;
    node->child=NULL;
    node->next=NULL;
    return node;
}//create

void addSibling(struct nary *child, int data){
    if(child==NULL)
        return;
    
    while(child->next)
        child=child->next;
    
    child->next = create(data);
    
}//addSibling

void addChild(struct nary *parent, int data){
    if(parent->child==NULL){
        parent->child=create(data);
    }
    else{
        addSibling(parent->child, data);
    }
}//addChild

void printSibling(struct nary *root){
    struct nary *temp = root;
    while(temp->next){
        printf("%d\t", temp->data);
        temp=temp->next;
    }//while
}//printSibling

void inorderTraversal(struct nary *root){
    if(!root)
        return;
    inorderTraversal(root->child);
    printf("%d\t", root->data);
    inorderTraversal(root->next);
}//inorderTraversal


void preorderTraversal(struct nary *root){
    if(!root)
        return;
    printf("%d\t", root->data);
    preorderTraversal(root->child);
    preorderTraversal(root->next);
}//preorderTraversal


void postorderTraversal(struct nary *root){
    if(!root)
        return;
    preorderTraversal(root->child);
    preorderTraversal(root->next);
    printf("%d\t", root->data);
}//postorderTraversal

void printLeafNodes(struct nary *root){
    if(!root)
        return;
    
    if(root->child==NULL){
        printf("%d\t", root->data);
    }
    
    printLeafNodes(root->child);
    printLeafNodes(root->next);
}//printLeafNodes

int main() {
	//code
// 	struct nary *root = create(1);
//     addChild(root, 3);
//     addChild(root, 2);
//     addChild(root, 4);
    
//     addChild(root->child, 5);
//     addChild(root->child, 6);
	
	struct nary *root = create(1);
	addChild(root, 2);
	addChild(root, 3);
	
	addChild(root->child, 4);
	addChild(root->child, 5);
	
	
	addChild(root->child->next, 6);
	
    	printf("\nInorder Traversal\t");
	inorderTraversal(root);
	printf("\nPreorder Traversal\t");
	preorderTraversal(root);
	printf("\nPostorder Traversal\t");
	postorderTraversal(root);
	
	printf("\nLeaf Nodes\t");
	printLeafNodes(root);
	
	return 0;
}

/*
Output:


Inorder Traversal	4	5	2	6	3	1	
Preorder Traversal	1	2	4	5	3	6	
Postorder Traversal	2	4	5	3	6	1	
Leaf Nodes	4	5	6	

*/
