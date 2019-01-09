/*
Vertical Sum in a given Binary Tree | Set 1
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.
Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 16
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

void findSum(struct tree *root,int hd,int sums[]){
    /*
        The horizontal distance range lies between [-MAX,MAX].
        So for the ease of access, we use hd + MAX/2
        root = 8th index.
    */
    
    int index = hd + MAX/2;
    if(root==NULL)
        return;
    sums[index]+=root->data;

    if(root->left!=NULL)
        findSum(root->left,hd-1,sums);
    if(root->right!=NULL)
        findSum(root->right,hd+1,sums);
}

int main(){
    struct tree *root = createNode(10);
    root->left=createNode(20);
    root->right=createNode(30);
    root->left->left=createNode(40);
    root->left->right=createNode(50);
    root->right->left=createNode(60);
    root->right->right=createNode(70);
    int sums[MAX+1]={0};
    findSum(root,0,sums);
    
    printf("\nVertical sum of a binary tree set\n");
    for(int i=0;i<sizeof(sums)/sizeof(sums[0]); i++){
        printf("%d\t",sums[i]);
    }
    
    return 0;
}



/*
output :


Vertical sum of a binary tree set
0	0	0	0	0	0	40	20	120	30	70	0	0	0	0	0	0
*/
