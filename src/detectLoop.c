/*

Detect loop in a linked list
Given a linked list, check if the the linked list has loop or not. Below diagram shows a linked list with a loop.

1->2->3->4->5->2;

Floyd’s Cycle-Finding Algorithm:
This is the fastest method. Traverse linked list using two pointers.Move one pointer by one and other pointer by two.  If these pointers meet at same node then 
there is a loop. If pointers do not meet then linked list doesn’t have loop.
*/

#include<stdio.h>
#include<stdlib.h>
struct list{
  int data;
  struct list* next;
};

struct list* createNode(int data){
    struct list* newnode = (struct list*)malloc(sizeof(struct list*));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void printList(struct list *head){
    while(head){
        printf("%d\t",head->data);
        head=head->next;
    }
}

int detectLoop(struct list *start){
    struct list *head=start;
    while(start && head && start->next){
        head=head->next;
        start=start->next->next;
        if(head==start)
            return 1;
        }
    return 0;
}

int main(){
    
    struct list *head=createNode(100);
    struct list *q=head;
   
    for(int i=0;i<4;i++){
        struct list *p=createNode(i*10);
        q->next=p;
        q=p;
    }
    q->next=head->next;
    // printList(head);
    
    if(detectLoop(head))
        printf("Loop found");
    else
        printf("No loop found");
    
    
    return 0;
}

/*
output:
Loop found
*/
