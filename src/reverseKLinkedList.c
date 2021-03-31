/*
Reverse a Linked List in groups of given size. 
Medium Accuracy: 45.83% Submissions: 75282 Points: 4
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104
1 <= k <= N
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list {
    int data;
    struct list *next;
};

struct list *create(int data){
    struct list *newnode = (struct list *)malloc(sizeof(struct list));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}//create

struct list *reverse(struct list *head){
    struct list *curr = head, *prev=NULL, *next=NULL;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }//while
    
    return prev;
}

void traverse(struct list *head){
    struct list *temp = head;
    while(temp){
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}//traverse

struct list *getEndOfList(struct list *head, int k){
    struct list *temp = head;
    for(int i=0;i<k-1 && temp->next;i++){
        temp=temp->next;
    }//for
    return temp;
}//getEndOfList

int length(struct list *head){
    struct list *temp = head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}//length

struct list *reverseKList(struct list *head, int k){
    struct list *temphead = head, *prev = NULL;
    int count = length(head);

    count = (count%2)==0?(count/k):(count/k)+1;
    
    for(int i=0;i<count && temphead;i++){
        struct list *end = getEndOfList(temphead, k);
        // printf("%d %d\n", end->data, end->next->data);

        struct list *newstart = end->next;
        end->next = NULL;
        if(i==0){
            end = temphead;
            head = reverse(temphead);
            temphead = head;
        }
        else{
            end = temphead;
            temphead = reverse(temphead);
            prev->next = temphead;
        }
        end->next = newstart;
        prev=end;
        temphead = newstart;
    }//for
    traverse(head);
    
}//reverseKList

int main() {
//     struct list *head = create(1);
// 	head->next = create(2);
// 	head->next->next = create(3);
// 	head->next->next->next = create(4); 
// 	head->next->next->next->next = create(5);
	

	struct list *head = create(1);
	head->next = create(2);
	head->next->next = create(2);
	head->next->next->next = create(4); 
	head->next->next->next->next = create(5);
	head->next->next->next->next->next = create(6);
	head->next->next->next->next->next->next = create(7);
	head->next->next->next->next->next->next->next = create(8);
	
	
	reverseKList(head, 4);
	return 0;
}

/*
output:
4	2	2	1	8	7	6	5	
*/
