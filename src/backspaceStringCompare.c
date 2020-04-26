/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 300


#define MAX 300

struct deque{
  char *array;
  int front, rear;
  unsigned capacity;
};

struct deque *init(unsigned capacity){
    struct deque *d = (struct deque *)malloc(sizeof(struct deque));
    d->capacity = capacity;
    d->array = (char *)malloc(sizeof(char) * d->capacity);
    d->front=d->rear=-1;
    return d;
}//deque

int isFull(struct deque *d){
    return d->rear==d->capacity-1;
}//isFull

int isEmpty(struct deque *d){
    return d->front==-1;
}//isEmpty

void insertRear(struct deque *d, char key){
    if(isFull(d))
        return;
    if(isEmpty(d)){
        d->front=d->rear=0;
        d->array[d->rear++]=key;
    }//if
    else{
        d->array[d->rear++]=key;
    }//else
}//insertRear

char deleteRear(struct deque *d){
    if(isEmpty(d))
        return -1;
    char ch;
    if(d->front==d->rear){
        ch=d->array[d->rear];
        d->front=d->rear=-1;
    }//if
    else{
        ch=d->array[d->rear--];
    }//else
    return ch;
}//deleteRear

void insertString(struct deque *d, char ch){
    if(ch!='#')
            insertRear(d, ch);
    else if(!isEmpty(d))
        deleteRear(d);
}//insertString

int backspaceCompare(char * s, char *t){
    if(s==NULL || t==NULL)
        return 0;
    struct deque *d1=init(strlen(s)+1);
    struct deque *d2=init(strlen(t)+1);
    
    for(int i=0;i<strlen(s);i++){
        insertString(d1, s[i]);
    }//for
    
    for(int i=0;i<strlen(t);i++){
        insertString(d2, t[i]);
    }//for
    
    char ch1=deleteRear(d1);
    char ch2=deleteRear(d2);
    while(!isEmpty(d1) || !isEmpty(d2)){
        ch1=deleteRear(d1);
        ch2=deleteRear(d2);

        if(ch1!=ch2)
            return 0;
    }//while
    return 1;
}


int main() {
    char *s = "ad#c";
    char *t = "ab#c";
    
    if(backspaceCompare(s, t))
        printf("True");
    else
        printf("False");
    
	return 0;
}//main
