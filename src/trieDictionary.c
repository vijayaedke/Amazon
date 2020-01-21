#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 26

struct trie{
  struct trie *alphabets[size];
  int word;
  char *meaning;
};

struct trie *init(){
    struct trie *node = (struct trie *)malloc(sizeof(struct trie));
    for(int i=0;i<size;i++){
        node->alphabets[i] = NULL;
    }
    node->word=0;
    node->meaning = (char *)malloc(sizeof(char) * 100);
    
    return node;
}//init

void insert(char *str, char *meaning, struct trie *root){
    struct trie *temp = root;
    
    for(int i=0; i<strlen(str); i++){
        if(temp->alphabets[str[i] - 'a']==NULL){
            temp->alphabets[str[i] - 'a'] = init();
        }//if
        temp=temp->alphabets[str[i] - 'a'];
    }//for
    temp->word=1;
    strcpy(temp->meaning,  meaning);
}//insert

void search(struct trie *root, char *str){
    struct trie *temp = root;
    
    for(int i=0; i<strlen(str); i++){
        if(temp->alphabets[str[i] - 'a']==NULL){
            printf("Word %s doesn't exists in dictionary", str);
            return;
        }//if
        temp=temp->alphabets[str[i] - 'a'];
    }//for 
    
    int search = temp->word && temp!=NULL;
    if(search)
        printf("%s meaning %s", str, temp->meaning);
}//search

int main() {
    struct trie *root = init();
    
    insert("secular", "not connected with religious or spiritual matters.", root);
    insert("farrago", "a confused mixture.", root);
    insert("masquerade", "a false show or pretence.", root);
    
    search(root, "farrayugo");
    //search(root, "farrago");

    
    return 0;
    
}


/*
output : 
Word farrayugo doesn't exists in dictionary

output:
farrago meaning a confused mixture.

*/
