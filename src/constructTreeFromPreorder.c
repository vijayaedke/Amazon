/*
Construct BST from given preorder traversal | Set 1
Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.
     10
   /   \
  5     40
 /  \      \
1    7      50

The idea used here is inspired from method 3 of this post. The trick is to set a range {min .. max} for every node. Initialize the range as
{INT_MIN .. INT_MAX}. The first node will definitely be in range, so create root node. To construct the left subtree, set the range as
{INT_MIN …root->data}. If a values is in the range {INT_MIN .. root->data},the values is part part of left subtree.
To construct the right subtree, set the range as {root->data..max .. INT_MAX}.

*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

struct tree{
  int data;
  struct tree * left,*right;
};

struct tree *createNode(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}//createNode

struct tree *buildTree(int preorder[],int *index,int root,int min,int max,int size){
    if(*index>=size || min>max)
        return NULL;
    struct tree *node=NULL;
    if(root>min && root<max ){
        node=createNode(preorder[*index]);
        *index+=1;
        
        if(*index<size){
            node->left=buildTree(preorder,index,preorder[*index],min,root,size);
            node->right=buildTree(preorder,index,preorder[*index],root,max,size);
        }
        
    }//if
    return node;
}//buildTree

void printInorder (struct tree* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->data); 
    printInorder(node->right); 
} 

void constructTreeFromPreorder(int preorder[],int size){
    int index=0;
    // struct tree *root= buildTree(preorder,&index,0,size-1,size);
    struct tree *root=buildTree(preorder,&index,preorder[0],INT_MIN,INT_MAX,size);
    printInorder(root);
}//constructTreeFromPreorder()


int main(){
    int preorder[]={10, 5, 1, 7, 40, 50};
    int size=sizeof(preorder)/sizeof(preorder[0]);
    constructTreeFromPreorder(preorder,size);
    return 0;
}

/*
output:
1 5 7 10 40 50 
*/
