/*
Merge Sort for Linked Lists

Merge sort is often preferred for sorting a linked list. The slow random-access performance of a linked list makes some 
other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible.
sorting image

Let head be the first node of the linked list to be sorted and headRef be the pointer to head. Note that we need a reference
to head in MergeSort() as the below implementation changes next links to sort the linked lists (not data at the nodes), so 
head node has to be changed if the data at the original head is not the smallest value in the linked list.
*/
#include <stdio.h>
#include <stdlib.h>

struct list{
  int data;
  struct list *next;
};

struct list *createNode(int data){
    struct list *node  = (struct list *)malloc(sizeof(struct list));
    node->data=data;
    node->next=NULL;
    return node;
}//createNode

void printList(struct list *head){
    struct list *temp = head;
    printf("\n");
    while(temp){
        printf("%d\t", temp->data);
        temp=temp->next;
    }//while
}//printList

struct list *findMid(struct list *head){
    if(!head || !head->next)
        return head;
    struct list *temp=head, *mid=head, *prev=NULL;

    while(mid && temp && temp->next){
        prev=mid;
        mid=mid->next;
        temp=temp->next->next;
    }//while
    return prev;    
}//findMid

struct list *merge(struct list *l1, struct list *l2){
    if(!l1 && !l2)
        return NULL;
    
    struct list *dummy = createNode(-1), *temp = dummy;
    
    while(l1 && l2){
        if(l1->data < l2->data){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }//if
        else{
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }//else
    }//while
    
    if(l1)
        temp->next=l1;
    if(l2)
        temp->next=l2;
    return dummy->next;
}//merge

struct list *mergeSort(struct list *head){
    if(!head || !head->next)
        return head;
    
    struct list *mid = findMid(head);
    struct list *mid_next = mid->next;
    mid->next = NULL;
    
    struct list *l1 = mergeSort(head);
    struct list *l2 = mergeSort(mid_next);
    
    head = merge(l1, l2);
    return head;
}//mergeSort


int main() {
	//code
	struct list *head = createNode(40);
	head->next = createNode(20);
	head->next->next = createNode(60);
	head->next->next->next = createNode(10);
	head->next->next->next->next = createNode(50);
	head->next->next->next->next->next = createNode(30);
	
	printf("\nUnsorted list\n");
	printList(head);
	
	head = mergeSort(head);
	
	printf("\nSorted list\n");
	printList(head);
	
	return 0;
}

/*
output:

Unsorted list
40	20	60	10	50	30	

Sorted list
10	20	30	40	50	60	
*/
