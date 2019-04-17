/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.
*/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct ListNode{
    int val;
    struct ListNode *next;
};
 
struct ListNode *createNode(int data){
    struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
    newnode->val=data;
    newnode->next=NULL;
    return newnode;
} //createNode
 
int getSize(struct ListNode *head){
    int size=0;
    struct ListNode *temp=head;
    while(temp){
        size++;
        temp=temp->next;
    }
    return size;
}//getSize()

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL)
        return NULL;
    if(k==0 || head->next==NULL)
        return head;
    int size=getSize(head);
    
    if(k>size)
        k=k%size;
    
    struct ListNode *temp=head,*newhead=head,*prev=NULL;
    for(int i=0;i<k;i++){
        // printf("%d",i);
        temp=newhead;
        // printf("\nnewhead = %d\n",newhead->val);
        while(temp->next){
            prev=temp;
            temp=temp->next;
        }//while
        temp->next=newhead;
        prev->next=NULL;
        newhead=temp;
    }//for
    return newhead;
    // return NULL;
}


void printList(struct ListNode *head){
    struct ListNode *temp=head;
    printf("\n[");
    while(temp){
        printf("%d,",temp->val);
        temp=temp->next;
    }
    printf("]\n");
}

int main() {
   struct ListNode* head=createNode(1);
   head->next=createNode(2);
   head->next->next=createNode(3);
   head->next->next->next=createNode(4);
   head->next->next->next->next=createNode(5);

   int k=2;
   //print the initial list
   printList(head);
   
   //rotate a list
   head=rotateRight(head,k);
   
   //print the rotated List
   printList(head);
   return 0;
    
}

/*
Example 1
input : [1,2,3,4,5] k=2
output : [4,5,1,2,3]

Example 2
Input : [1,2,3] k 200000000
Output : [2,3,1]

Example 3
Input : [0,1,2] k = 4
Output: [2,0,1]


*/
