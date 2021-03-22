#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree *right, *left;
};

struct tree *create(int data){
    struct tree *node = (struct tree *)malloc(sizeof(struct tree));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

// struct tree *insert(struct tree *root, int data){
//     if(!root)
//         return create(data);
    
//     if(data<root->data){
//         root->left = insert(root->left, data);
//     }
//     else{
//       root->right = insert(root->right, data);
//     }
// }//insert

void insert(struct tree *root, int data){
    if(!root)
        return;
    struct tree *p=root, *q=root;
    while(p){
        if(data < p->data){
            q = p;
            p = p->left;
        }//if
        else{
            q = p;
            p = p->right;
        }//else
    }//while
    
    if(data < q->data)
        q->left = create(data);
    else
        q->right = create(data);
}

void inorder(struct tree *root){
    if(!root)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

int main() {
	//code
	struct tree *root = NULL;
	if(!root)
	    root= create(10);
	insert(root, 20);
	insert(root, 30);
    insert(root, 2);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 5);
    insert(root, 80);
    inorder(root);
	return 0;
}

/*
output : 2	5	10	20	30	40	60	70	80	
*/
