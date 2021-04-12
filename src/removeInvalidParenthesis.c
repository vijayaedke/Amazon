/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.
Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:
Input: s = ")("
Output: [""]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct stack{
    char *data;
    unsigned capacity;
    int top;
};

struct stack *init(unsigned capacity){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->top=-1;
    s->data = (char *)malloc(sizeof(char) * s->capacity);
    return s;
}//init

int isEmpty(struct stack *s){
    return s->top==-1;
}//isEmpty

int isFull(struct stack *s){
    return s->top==s->capacity-1;
}//isFull

void push(struct stack *s, char ch){
    if(isFull(s))
        return;
        
    s->data[++s->top] = ch;
}//push

char pop(struct stack *s){
    if(isEmpty(s))
        return 0;
        
    return s->data[s->top--];
}//pop

char peek(struct stack *s){
    return s->data[s->top];
}//peek

int getSize(struct stack *s){
    return s->top+1;
}//getSize

int getMinRemove(char *str){
    
    if(strlen(str)==0)
        return 0;
    struct stack *s = init(MAX);
    
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='('||(str[i]>=97 && str[i]<=123)){
            push(s, str[i]);
        }    
        else if(isEmpty(s) && str[i]==')'){
            push(s, str[i]);
        }
        else if(str[i]==')' && peek(s)==')'){
            push(s, str[i]);
        }
        else{
            pop(s);
        }
    }//for
    return getSize(s);
}//getMinRemove

int  contains(char *str, char **set){
    for(int i=0;i<MAX;i++){
        if(strcmp(str, set[i])==0){
            // printf("in here%s\n", set[i]);
            return 1;
        }
    }//for
    return 0;
}//contains

char *substring(char *str, int start, int end){
    char *newstr = (char *)malloc(sizeof(char)*MAX);
    int i;
    for(i=start;i<end;i++){
        newstr[i-start]=str[i];
    }
    newstr[i] = '\0';
    return newstr;
}

void strcopy(char **set, char *str, int index){
    int i, j=0;
    for(i=0;i<strlen(str);i++){
        // printf("in here\n");
        set[index][j++] = str[i];
    }
    set[index][j++]='\0';
    // printf("%s\n", set[index]);
}//strcopy

void solution(char *str, int minRemove, char **set, int n, int *index){
    
    if(minRemove==0){
        if(getMinRemove(str)==0){// && !contains(str, set)){
            if(!contains(str, set)){
                strcopy(set, str, *index);
                printf("%s\n", str);
                (*index)++;
            }
        }//if
        return;
    }//if
    
    for(int i=0;i<strlen(str);i++){
        // if(str[i]>=97 && str[i]<=123)
        //     i++;
        char *left = substring(str, 0, i);
        // printf("left = %s", left);
        char *right = substring(str, i+1, n);
        // printf("\nright = %s\n", right);
        solution(strcat(left, right), minRemove-1, set, n, index);
    }//for
    
}//solution

int main() {
	char *str="()())()";
// 	char *str=")(";
// 	char *str="(a)())()";

	int min = getMinRemove(str);
	char **set = (char **)malloc(sizeof(char*)*MAX);
	for(int i=0;i<MAX;i++)
	    set[i] = (char *)malloc(sizeof(char) * MAX);
	int index=0;
	solution(str, min, set, strlen(str), &index);
// 	printf("%d", min);
	return 0;
}

/*
output:
(())()
()()()

*/
