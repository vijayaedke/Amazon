#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 26

struct wordDictionary{
    int isEndOfWord;
    struct wordDictionary *node[SIZE];
}typedef dictionary;


dictionary* getNode(){
    dictionary *d = (dictionary *)malloc(sizeof(dictionary));
    if(d){
        d->isEndOfWord=0;
        
        for(int i=0; i<SIZE; i++)
            d->node[i]=NULL;
    }//if
    return d;
}//getNode

char *toLower(char *src){
    char *dest = malloc(sizeof(char) * strlen(src));
    for(int i=0;i<strlen(src);i++){
        if(src[i]>='A' && src[i]<='Z')
            dest[i] = src[i]+32;
        else
            dest[i]=src[i];
    }//for
    
    return dest;
}//tolower

void add(dictionary *d, char *word){
    if(d==NULL || strlen(word) == 0)
        return;
    dictionary *curr=d;
    
    word = toLower(word);
    for(int i=0;i<strlen(word);i++){
        int index = word[i] - 97;

        if(!curr->node[index])
            curr->node[index]=getNode();
            
        curr=curr->node[index];
    }//for
    
    curr->isEndOfWord=1;
}//add

char *substr(char *word, int start_offset, int len){
    int i, dest_len=len-start_offset+1;
    char *dest=malloc(sizeof(char) * dest_len);
   for (int i = start_offset; i <len && (*word != '\0'); i++)
	{
		*dest = *(word + i);
		dest++;
	}

	// null-terminate the destination string
	*dest = '\0';
    // printf("\ndest = %s", dest);
    return dest - dest_len;
}//substr

int search(dictionary *d, char *key){
    int len=strlen(key);
    
    if(d==NULL || len==0)
        return 0;
    
    dictionary *curr = d;
    
    for(int i=0; i<len; i++){
        int index = key[i] - 97;
        if(key[i]>='a' && key[i]<='z' ){
            if(!curr->node[index])
                return 0;
            curr=curr->node[index];
        }//if
        else{
            printf("\nKey = %s", key);
            int found = 0;
                int j = 0;
                for(; j < 26; j++){
                    char *n_key = substr(key,i + 1,len);
                    printf("\nNew key = %s", n_key);
                    if(curr->node[j]) found |= search( curr->node[j] ,n_key );
                    if(found) return 1;
                }
                if(j == 26) return 0;
        }//else
    }//for
    
    return curr->isEndOfWord;
}//search

int main() {
    
    dictionary *root = getNode();
    add(root, "v");
    if(search(root,"."))
        printf("\nfound \n");
    else
        printf("\nNot found \n");
    
    
    return 0;
}
