/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/


#include<stdio.h>
#include<stdlib.h>

struct ListNode{
  int val;
  struct ListNode *next;
};

struct ListNode *getNode(int data){
    struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
    node->val=data;
    node->next=NULL;
    return node;
}//createNode
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head,*s;
    
    if(l1==NULL && l2==NULL)
        return NULL;
        
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    
    head=getNode(0);
    s=head;
    //printf("\nList1  = %p %d\nList2 =%p %d\n\nhead %p",l1,l1->val,l2,l2->val,head);
    while(l1 && l2){
        if(l1->val<=l2->val){
            s->next=l1;
            l1=l1->next;
        }//if
        else{
            s->next=l2;
            l2=l2->next;
        }//else
        s=s->next;
    }//while
    
    s->next = l1!=NULL ? l1:l2;
    
    return head->next;
}//mergeTwoLists

void printList(struct ListNode *temp){
    while(temp){
        printf("%d->",temp->val);
        temp=temp->next;
    }//while
}//printList

int main() {
    struct ListNode *l1=getNode(5);
    // l1->next=getNode(2);
    // l1->next->next=getNode(4);
    
    struct ListNode *l2=getNode(1);
    l2->next=getNode(3);
    l2->next->next=getNode(4);
    
    printf("\n*******List1*******\n");
    printList(l1);
    
    printf("\n*******List1*******\n");
    printList(l2);
    
    struct ListNode *res=mergeTwoLists(l1, l2);
    printf("\nMerged List\n");
    printList(res);
    
    return 0;
    
}

/*
output:

*******List1*******
5->
*******List1*******
1->3->4->

Merged List
1->3->4->5->
*/
