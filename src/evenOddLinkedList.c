/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

#include <stdio.h>
#include <stdlib.h>

struct list{
  int data;
  struct list *next;
};

struct list *create(int data){
    struct list *node = (struct list *)malloc(sizeof(struct list));
    node->data=data;
    node->next=NULL;
    return node;
}//create

void print(struct list *head){
    struct list *temp=head;
    while(temp){
        printf("%d\t", temp->data);
        temp=temp->next;
    }//while
    
}//print

struct list *evenOddSort(struct list *head){
    struct list *evenhead = head->next;
    struct list *oddhead = head;
    struct list *p=oddhead, *q=evenhead;
    
    while(p->next && q->next){
        p->next = q->next;
        p=q->next;
        q->next = p->next;
        q=p->next;
    }//while
    
    p->next = evenhead;
    
    return oddhead;
}//evenOddSort

int main() {
	//code
// 	struct list *head = create(1);
// 	head->next=create(2);
// 	head->next->next=create(3);
// 	head->next->next->next=create(4);
// 	head->next->next->next->next=create(5);
	
	struct list *head = create(2);
	head->next=create(1);
	head->next->next=create(3);
	head->next->next->next=create(5);
	head->next->next->next->next=create(6);
	head->next->next->next->next->next=create(4);
	head->next->next->next->next->next->next=create(7);
	
	printf("\nBefore sorting\n");
	print(head);
	
	head = evenOddSort(head);
	printf("\nAfter sorting\n");
	print(head);
	
	return 0;
}

/*
output:

Before sorting
2	1	3	5	6	4	7	
After sorting
2	3	6	7	1	5	4	
*/
