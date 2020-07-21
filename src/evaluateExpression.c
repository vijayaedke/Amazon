/*
Evaluation of Expression Tree
Given a simple expression tree, consisting of basic binary operators i.e., + , – ,* and / and some integers, evaluate the expression tree.

Examples:


Input :
Root node of the below tree
            +
        /     \
      *         -
    /   \     /   \
  5       4  100    20

Output :
100

Input :
Root node of the below tree
            +
        /     \
      *         -
    /   \     /   \
  5       4  100    /
                  /   \
                20      2

Output :
110
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree {
  char *data;
  struct tree *left,*right;
};

struct tree *createNode(char *data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int toInt(char *str){
    int sum=0, flag=0;
    if(str[0]=='-')
        flag=1;
        
    int len = flag?strlen(str)-1:strlen(str);
    
    for(int i=0;i<len;i++){
        int n1 = (str[i]-48);
        sum = n1+(10 * sum);
    }//for
    
    return flag?(sum*-1):sum;
}//toInt

int evaluate(struct tree *root){
    if(!root)
        return 0;

    if(!root->left && !root->right)
        return toInt(root->data);
        
    int x = evaluate(root->left);
    int y = evaluate(root->right);

    if(root->data == "*")
        return x*y;
    else if(root->data == "+")
        return x+y;
    else if(root->data == "/")
        return x/y;
    return  x-y;
    // return 0;
}//diff

int main() {
	struct tree *root = createNode("+");
	root->left = createNode("*");
	root->right = createNode("-");
	
	root->left->left = createNode("5");
	root->left->right = createNode("4");
	
    root->right->left = createNode("100");
    root->right->right = createNode("/");
    
    root->right->right->left = createNode("20");
    root->right->right->right = createNode("2");
    
    
    int res = evaluate(root);
    if(res)
        printf("\nRes = %d", res);
    
	return 0;
}

/*output :
Res = 110
*/
