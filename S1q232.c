/*************************************************************************
	> File Name: S1q232.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 May 2024 08:08:46 PM CST
 ************************************************************************/

typedef struct stack{
    int *arr;
    int top;
    int size;
}stack;

stack *stackcreate(int size){
    stack *ret = (stack *)malloc(sizeof(stack));
    ret->arr = (int *)malloc(size * sizeof(int));
    ret->top = 0;
    ret->size = size;
    return ret;
}

void stackpush(stack *ret, int val){
    ret->arr[ret->top++] = val;
}

void stackpop(stack *ret){
    ret->top--;
}

int stacktop(stack *ret){
    return ret->arr[ret->top - 1];
}

bool stackempty(stack *ret){    
    return ret->top == 0;
}

void stackfree(stack *ret){
    free(ret->arr);
    free(ret);
}


typedef struct {
    stack *instack;
    stack *outstack;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *ret = (MyQueue *)malloc(sizeof(MyQueue));
    ret->instack = stackcreate(100);
    ret->outstack = stackcreate(100);
    return ret;
}

void inout(MyQueue *ret){
    while (!stackempty(ret->instack)){
        stackpush(ret->outstack, stacktop(ret->instack));
        stackpop(ret->instack);
    }
    ret->instack->top = 0; // 更新 instack 的 top
}

void myQueuePush(MyQueue* ret, int x) {
    stackpush(ret->instack, x);
}

int myQueuePop(MyQueue* ret) {
    if (stackempty(ret->outstack)){
        inout(ret);
    }
    int x = stacktop(ret->outstack);
    stackpop(ret->outstack);
    return x;
}

int myQueuePeek(MyQueue* ret) {
    if (stackempty(ret->outstack)){
        inout(ret);
    }
    return stacktop(ret->outstack);
}

bool myQueueEmpty(MyQueue* ret) {
    return stackempty(ret->instack) && stackempty(ret->outstack);
}

void myQueueFree(MyQueue* ret) {
    stackfree(ret->instack);
    stackfree(ret->outstack);
    free(ret);
}

