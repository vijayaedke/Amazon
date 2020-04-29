/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.

*/


#define MAX 10000


typedef struct {
    int *array;
    int *min;
    int top,top1;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->array=(int *)malloc(sizeof(int) * MAX);
    obj->min=(int *)malloc(sizeof(int) * MAX);
    for(int i=0;i<MAX;i++)
        obj->min[i]=0;
    obj->top=-1;
    obj->top1=-1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top==MAX-1)
        return;
    
    if(obj->top==-1){
        obj->array[++obj->top] = x;
        obj->min[++obj->top1] = x;
    }
    else{
        obj->array[++obj->top] = x;
        // if(
        obj->min[++obj->top1] = x < obj->min[obj->top1] ? x : obj->min[obj->top1];
    }
    printf("\nmin %d stack %d", obj->min[obj->top1], obj->array[obj->top]);
}

void minStackPop(MinStack* obj) {
  if(obj->top==-1)
      return;
  obj->array[obj->top--];
  // if(x == obj->min[obj->top1])
  obj->min[obj->top1--];
}

int minStackTop(MinStack* obj) {
  return obj->array[obj->top];
}

int minStackGetMin(MinStack* obj) {
  if(obj->top1==-1)
      return 0;
  return obj->min[obj->top1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
