/*
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct tree{
  struct tree *right, *left;
  char *data;
};

struct tree * createNode(char *str){
    struct tree *node=(struct tree *)malloc(sizeof(struct tree));
    node->data = str;
    node->left=node->right;
    return node;
}//createNode


int findHeight(struct tree *root, int height){
    if(root==NULL)
        return height;
    
    int left = findHeight(root->left, height+1);
    int right = findHeight(root->right, height+1);
    
    return left>right ? left :right;
}//findHeight

char*** init(int row, int col){
    char ***output = (char ***)malloc(sizeof(char **) * row);
    for(int i=0;i<row;i++){
        output[i] = (char **)malloc(sizeof(char *) * col);
        for(int j=0;j<col;j++){
            output[i][j] = (char *)malloc(sizeof(char) * 10);
            output[i][j] = NULL;
        }//for j
    }//for i
    return output;
}//init


void printOuput(char ***output,int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(output[i][j])
                printf("%s", output[i][j]);
            else
                printf("\"\"");
        }//for j
        printf("\n");
    }//for i
}//printOuput

void printBinary(struct tree *root, char*** output, int row, int col){
    if(root==NULL)
        return;
    // printf("\nCurrent data = %s", root->data);
    if(root->left){
        int lcol = (int)col/2;
        output[row][lcol] = root->left->data;
        // printf("\nLeft = %d %d %s", row, col, output[row][lcol]);
        printBinary(root->left, output, row+1, col/2);
    }//if
    
    if(root->right){
        int rcol = (col + (int)(col/2) +1);
        output[row][rcol] = root->right->data;
        // printf("\nRight = %d %d %s", row,  rcol, output[row][rcol]);
        printBinary(root->right, output, row+1, (col + (int)(col/2) +1) );
    }//if
        
}//printBinaryx

int main() {
	//code
	struct tree *root = createNode("10");
	root->left = createNode("20");
	root->right = createNode("50");
	
	root->left->left = createNode("30");
	root->left->left->left = createNode("40");

	int height = findHeight(root, 0);
// 	printf("Height = %d", height);
	
	int row = height, col = pow(2, height)-1;
	char ***output = init(row, col);
	col=(int)col/2;
// 	printf("\n%d  %d", row, col);
	output[0][col]=root->data;
// 	printBinary(root, output, 1, (int)col/2, 1, col+(int)col/2+1);

    printBinary(root, output, 1, col);
	
	printf("\n\n");
	printOuput(output, height, pow(2, height)-1);
	
	return 0;
}


/*
output:

""""""""""""""10""""""""""""""
""""""20""""""""""""""50""""""
""30""""""""""""""""""""""""""
40""""""""""""""""""""""""""""

*/
