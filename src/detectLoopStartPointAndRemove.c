/*
Remove loop in Linked List 
Medium Accuracy: 47.96% Submissions: 100k+ Points: 4
You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 
â€‹
Example 2:

Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not 
contains any loop. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct list{
    int data;
    struct list *next;
};

struct list *newNode(int data){
    struct list *node = (struct list *)malloc(sizeof(struct list));
    node->data = data;
    node->next = NULL;
    return node;
}//newNode

struct list *detectAndRemoveLoop(struct list *head){
    if(!head || !head->next)
        return NULL;
        
    struct list *slow=head, *fast=head, *prev=NULL;
    
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    
    if(slow!=fast)
        return NULL;
    
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    
    return slow;
}//detectAndRemoveLoop

void removeLoop(struct list *res, struct list *head){
    struct list *ptr1 = res, *ptr2 = res;
    
    while(ptr1->next!=ptr2){
        ptr1=ptr1->next;
    }//while
    
    ptr1->next = NULL;
}//removeLoop

void traverse(struct list *head){
    while(head){
        printf("%d\t", head->data);
        head = head->next;
    }//while
    
}//traverse

int main() {
    struct list *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    struct list *res = detectAndRemoveLoop(head);
    if (res == NULL)
        printf("Loop does not exist");
    else{
        printf("Loop starting node is %d\n" , res->data);
        removeLoop(res, head);
        traverse(head);
    }
	return 0;
}

/*
Loop starting node is 3
1	2	3	4	5	

*/
