/*
Huffman Encoding 
Medium Accuracy: 39.51% Submissions: 375 Points: 4
Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: If two elements have same frequency, then the element which occur at first will be taken on the left of Binary Tree and other one to the right.

Example 1:

S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
Explanation:
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary 
Tree.
Your Task:
You don't need to read or print anything. Your task is to complete the function huffmanCodes() which takes the given string S, frequency array f[ ] and number of characters N as input parameters and returns a vector of strings containing all huffman codes in order of preorder traversal of the tree.

Expected Time complexity: O(N * LogN) 
Expected Space complexity: O(N) 

Constraints:
1 ≤ N ≤ 26


*/
#include <stdio.h>
#include <stdlib.h>

struct minHeap{
    int size;
    struct heapNode **array;
};

struct heapNode{
    int freq;
    char data;
    struct heapNode *left, *right;
};

struct minHeap *initHeap(unsigned capacity){
    struct minHeap *mh = (struct minHeap *)malloc(sizeof(struct minHeap));
    mh->size = capacity;
    mh->array = (struct heapNode **)malloc(sizeof(struct heapNode *) * mh->size);
    return mh;
}//initHeap

struct heapNode *create(char data, int freq){
    struct heapNode *node = (struct heapNode *)malloc(sizeof(struct heapNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}//create

void swap(struct heapNode **a, struct heapNode  **b){
    struct heapNode *temp = *a;
    *a = *b;
    *b = temp;
}//swap

void heapify(struct minHeap *mh, int index, int n){
    int right = 2*index+2;
    int left = 2*index+1;
    int root = index;
    
    if(left<n && mh->array[root]->freq > mh->array[left]->freq)
        root = left;
    if(right<n && mh->array[root]->freq > mh->array[right]->freq)
        root = right;
    
    if(root!=index){
        swap(&mh->array[root], &mh->array[index]);
        heapify(mh, root, n);
    }
    
}//heapify

struct heapNode *extractMin(struct minHeap *mh){
    struct heapNode *node = mh->array[0];
    mh->array[0] = mh->array[mh->size-1];
    mh->size--;
    heapify(mh, 0, mh->size);
    
    return node;
}//extractMin

void insertMinHeap(struct minHeap *mh, struct heapNode *newnode){
    ++mh->size;
    int size = mh->size-1;
    while(size && mh->array[(size-1)/2]->freq > newnode->freq){
        mh->array[size] = mh->array[(size-1)/2];
        size = (size-1)/2;
    }//while
    
    mh->array[size] = newnode;
}//insertMinHeap

struct heapNode *buildMinHeap(char *data, int *freq, int size){
    struct minHeap *mh = initHeap(size);
    for(int i=0;i<mh->size;i++)
        mh->array[i] = create(data[i], freq[i]);
    
    heapify(mh, 0, mh->size);
    
    while(mh->size!=1){
        struct heapNode *left = extractMin(mh);
        if(left)
            printf("%c %d\n", left->data, left->freq);
        struct heapNode *right = extractMin(mh);
        if(right)
            printf("%c %d\n", right->data, right->freq);

        struct heapNode *newnode = create('$', left->freq+right->freq);
        newnode->left = left;
        newnode->right = right;
        
        insertMinHeap(mh, newnode);
        printf("\n");
    }
    return extractMin(mh);
}//buildMinHeap

void printArray(int *array, int index){
    // printf("\nindex %d", index);
    for(int i=0;i<index;i++)
        printf("%d", array[i]);
}//printArray

void printCodes(struct heapNode *root, int array[], int index){
    if(root->left){
        array[index] = 0;
        // printf("root %d left %d\t",root->freq, root->left->freq);
        printCodes(root->left, array, index+1);
    }//if
    if(root->right){
        array[index] = 1;
        // printf("root %d right %d\t",root->freq, root->right->freq);
        printCodes(root->right, array, index+1);
    }//if
    if(!root->left && !root->right){
        printf("%c : ", root->data);
        printArray(array, index);
        printf("\n");
    }
}//printCodes

void huffmanCode(char *data, int *freq, int size){
    
    struct heapNode *root = buildMinHeap(data, freq, size);
    int array[100]={0}, index=0;
    printCodes(root, array, index);
}//huffmanCode

int main() {
	//code
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(freq)/sizeof(freq[0]);
    huffmanCode(arr, freq, size);
	
	return 0;
}

/*
output:
a 5
b 9

c 12
d 13

$ 14
e 16

$ 25
$ 30

f 45
$ 55

f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111

*/
