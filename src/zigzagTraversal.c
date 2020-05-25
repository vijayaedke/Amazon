/*
Write a function to print ZigZag order traversal of a binary tree. For the below binary tree the zigzag order
traversal will be 1 3 2 7 6 5 4

input :
         1
      /     \
    2         3
  /   \     /    \
7       6  5      4

output : 
1	3	2	7	6	5	4	

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct tree{
  int data;
  struct tree *left, *right;
};

struct stack{
  int top;
  unsigned capacity;
  struct tree **array;
};

struct tree *create(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->left=NULL;
    node->right=NULL;
    return node;
}//create

struct stack *init(unsigned capacity){
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->capacity = capacity;
    s1->array = (struct tree **)malloc(sizeof(struct tree *) * s1->capacity);
    s1->top=-1;
    return s1;
}//init

int isEmpty(struct stack *s){
    return s->top==-1;
}//isEmpty

int isFull(struct stack *s){
    return s->top==s->capacity-1;
}//isFull

void push(struct stack *s, struct tree *node){
    if(isFull(s))
        return;
    
    if(node==NULL)
        return;
    s->array[++s->top] = node;
}//push

struct tree *pop(struct stack *s){
    if(isEmpty(s))
        return NULL;
    
    return s->array[s->top--];    
}//pop

void zigzagTraversal(struct tree *root){
    struct stack *s1 = init(MAX);
    struct stack *s2 = init(MAX);
    
    push(s1, root);

    while(!isEmpty(s1) || !isEmpty(s2)){
        
        //push nodes into s1 from left to right
        while(!isEmpty(s1)){
            struct tree *temp = pop(s1);
            printf("%d\t", temp->data);
            push(s2, temp->left);
            push(s2, temp->right);
        }//while
        
        
        //push nodes into s1 from right to left
        while(!isEmpty(s2)){
            struct tree *temp = pop(s2);
            printf("%d\t", temp->data);
            push(s1, temp->right);
            push(s1, temp->left);
        }//while
        // pop(s1);
    }//while
    
}//zigzagTraversal

int main() {
	//code
	struct tree *root = create(1);
	root->left = create(2);
	root->right = create(3);
	
	root->left->left = create(7);
	root->left->right = create(6);
	
	root->right->left = create(5);
	root->right->right = create(4);
	
	zigzagTraversal(root);
	return 0;
}
