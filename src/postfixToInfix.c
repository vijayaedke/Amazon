/*
Postfix to Infix
Difficulty Level : Easy
Last Updated : 08 Feb, 2019

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Postfix notation, also known as reverse Polish notation, is a syntax for mathematical expressions in which the 
mathematical operator is always placed after the operands. Though postfix expressions are easily and efficiently 
evaluated by computers, they can be difficult for humans to read. Complex expressions using standard parenthesized 
infix notation are often more readable than the corresponding postfix expressions. Consequently, we would sometimes
like to allow end users to work with infix notation and then convert it to postfix notation for computer processing. 
Sometimes, moreover, expressions are stored or generated in postfix, and we would like to convert them to infix for
the purpose of reading and editing

Examples:

Input : abc++
Output : (a + (b + c))

Input  : ab*c+
Output : ((a*b)+c)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
  char **ch;
  int top;
  unsigned capacity;
};

struct stack *init(unsigned capacity){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->ch = (char **)malloc(sizeof(char *) * 100);
    s->top=-1;
}//init

int isEmpty(struct stack *s){
    return s->top==-1;
}//isEmpty

int isFull(struct stack *s){
    return s->top==s->capacity-1;
}//isFull

void push(struct stack *s, char *val){
    if(isFull(s))
        return;
    
    s->ch[++s->top] = val;
    printf("Pushed %s\n", s->ch[s->top]);
}//push

char* pop(struct stack *s){
    if(isEmpty(s))
        return "";
        
    return s->ch[s->top--];
}

// int evaluatePostExpression(char *str){
//     struct stack *s = init(strlen(str));
//     int i=0;
//     while(str[i]!='\0'){
//         if(str[i]>=48 && str[i]<=57){
//             push(s, str[i]-48);
//         }
//         else{
//             int y = pop(s);
//             int x = pop(s);
//             printf("%d %d\n", x, y);
//             switch(str[i]){
//                 case '*':
//                     push(s, (x*y));
//                 break;
//                 case '+':
//                     push(s, (x+y));
//                 break;
//                 case '/':
//                     push(s, (x/y));
//                 break;
//                 case '-':
//                     push(s, (x-y));
//                 break;
//             }
//         }
//         i++;
//     }//while
//     return pop(s);
// }//evaluatePostExpression

char *getstr(char ch){
    char *str = (char *)malloc(sizeof(char) * 2);
    str[0] = ch;
    str[1] = '\0';
    return str;
}

char *createStr(char *exp){
    char *str = (char *)malloc(sizeof(char) * 100);
    str[0] = '(';
    strcat(str, exp);
    str[strlen(str)] = ')';
    str[strlen(str)]='\0';
    return str;
}//createStr

char *postfixToInfixConversion(char *str){
    
    if(strlen(str)==0)
        return NULL;
    struct stack *s = init(strlen(str));
    
    for(int i=0; i<strlen(str); i++){
        if(str[i]>=97 && str[i]<=123){
            push(s, getstr(str[i]));
        }
        else{
            char *x = pop(s);
            char *y = pop(s);
            printf("%s %s\n", x, y);
            switch(str[i]){
                case '*':
                    strcat(y,"*");
                    strcat(y, x);
                    push(s, createStr(y));
                break;
                case '+':
                    strcat(y,"+");
                    strcat(y, x);
                    push(s, createStr(y));
                break;
                case '/':
                    strcat(y,"/");
                    strcat(y, x);
                    push(s, createStr(y));
                break;
                case '-':
                    strcat(y,"-");
                    strcat(y, x);
                    push(s, createStr(y));
                break;
            }
        }
        
    }//for
    return pop(s);
}//postfixToInfixConversion

int main() {
	//code
    // char *str="231*+9-";
    char *str="ab*c+";
    // printf("%d\t", evaluatePostExpression(str));
    printf("%s\t", postfixToInfixConversion(str));
	return 0;
}
/*
Pushed a
Pushed b
b a
Pushed (a*b)
Pushed c
c (a*b)
Pushed ((a*b)+c)
((a*b)+c)	
*/
