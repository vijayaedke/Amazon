/*
Find a pair with given sum in a Balanced BST
Given a Balanced Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum equals to target sum, 
otherwise return false. Expected time complexity is O(n) and only O(Logn) extra space can be used. Any modification to Binary Search Tree is 
not allowed. Note that height of a Balanced BST is always O(Logn).

 create an auxiliary array and store Inorder traversal of BST in the array. The array will be sorted as Inorder traversal of BST always 
 produces sorted data. Once we have the Inorder traversal, we can pair in O(n) time (See this for details). This solution works in O(n) 
 time, but requires O(n) auxiliary space.
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

void inorder(struct tree *root, int *array, int *index){
    if(!root)
        return;
    inorder(root->left, array, index);
    array[(*index)++] = root->data;
    inorder(root->right, array, index);
}

int countNodes(struct tree *root, int *count){
    if(!root)
        return 0;
    if(root)
        *count+=1;
    
    countNodes(root->left, count);
    countNodes(root->right, count);
    
    return *count;
}//countNodes

int *init(int count){
    int *array = (int *)malloc(sizeof(int) * count);
    for(int i=0;i<count;i++)
        array[i] =0;
    return array;
}

void findPair(struct tree *root, int sum){
    int count =0;
    count = countNodes(root, &count);
    int *array = init(count);
    inorder(root, array, &count);
    
    int l=0, r=count-1;
    
    while(l<r){
        if((array[l]+array[r])==sum){
            printf("%d %d", array[l], array[r]);
            return;
        }//if
        
        else if( (array[l]+array[r]) < sum )
            l++;
        else
            r--;
    }//while
}//findPair

int main() {
	//code
    struct tree *root = createNode(15);
    root->left = createNode(10);
    root->right = createNode(20);
    
    root->left->left = createNode(8);
    root->left->right = createNode(12);
    
    root->right->left = createNode(16);
    root->right->right = createNode(25);
    
    findPair(root, 32);
    
    return 0;
}

/*
output:
12 20

*/


