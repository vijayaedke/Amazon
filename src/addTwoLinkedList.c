/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/


#include<stdio.h>
#include<stdlib.h>

struct ListNode{
  int val;
  struct ListNode *next;
};

struct ListNode* getNode(int data){
    struct ListNode *current=(struct ListNode *)malloc(sizeof(struct ListNode));
    current->val=data;
    current->next=NULL;
    return current;
}//getNode

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum=0,carry=0;
    struct ListNode *current=NULL;
    struct ListNode *p=l1,*q=l2,*temp;
    
    while(p || q){
        int x = (p!=NULL)?p->val:0;
        int y = (q!=NULL)?q->val:0;
        
        sum = carry + x +y;
        if(sum>9){
            carry=sum/10;
            sum%=10;
        }//if
        else{
            carry=0;
        }//else
        
        if(current==NULL){
            current=getNode(sum);
            temp=current;
        }
        else{
            struct ListNode *newnode=getNode(sum);
            temp->next=newnode;
            temp=newnode;
        }
        
        if(p!=NULL) { p=p->next; }
        if(q!=NULL) { q=q->next; }
    }//while
    
    if(carry>0){
        struct ListNode *newnode=getNode(carry);
        temp->next=newnode;
    }
    return current;
}//addTwoNumbers

void printList(struct ListNode *node){
    struct ListNode *temp=node;
    while(temp){
        printf("%d->",temp->val);
        temp=temp->next;
    }
    printf("NULL");
}

int main() {
    //case 1
   //linkedlist 1
  struct ListNode *head1 = getNode(2);
  head1->next=getNode(4);
  head1->next->next=getNode(3);
   
  //linkedlist 2
  struct ListNode *head2=getNode(5);
  head2->next=getNode(4);
  head2->next->next=getNode(6);
   
     //case 2
   //linkedlist 1
   struct ListNode *head1 = getNode(5);
   
   //linkedlist 2
   struct ListNode *head2=getNode(5);
   
   //print 2 list
   printf("( ");
   printList(head1);
   printf(" ) + ( ");
   printList(head2);
   printf(") = ");
   
   //resultant linkedlist
   struct ListNode *result=addTwoNumbers(head1,head2);
   printList(result);
   
}
