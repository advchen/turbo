/*************************************************************************
	> File Name: S2q155.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 May 2024 07:33:03 PM CST
 ************************************************************************/
#define MAXSIZE 1600

typedef struct {
    int *data;  // 数据数组
    int top;    // 栈顶索引
} MinStack;

/** 初始化数据结构 */
MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->data = (int *)malloc(MAXSIZE * sizeof(int));
    obj->top = -1;
    return obj;
}

/** 向栈中添加元素 x */
void minStackPush(MinStack* obj, int x) {
    if (obj->top >= MAXSIZE - 2) {
        // 栈溢出处理：这里可以添加相应的处理逻辑，例如重新分配更大的空间或打印错误
        return;
    }
    if (obj->top == -1) {
        obj->top++;
        obj->data[obj->top] = x; // 压入元素
        obj->top++;
        obj->data[obj->top] = x; // 压入最小元素
    } else {
        int currentMin = obj->data[obj->top];
        obj->top++;
        obj->data[obj->top] = x; // 压入元素
        obj->top++;
        obj->data[obj->top] = (x < currentMin) ? x : currentMin; // 压入最小元素
    }
}

/** 弹出栈顶元素 */
void minStackPop(MinStack* obj) {
    if (obj->top > -1) {
        obj->top--; // 弹出最小元素
        obj->top--; // 弹出元素
    }
}

/** 获取栈顶元素 */
int minStackTop(MinStack* obj) {
    if (obj->top == -1) {
        // 错误处理：栈为空
        return -1; // 或其他错误码/值
    }
    return obj->data[obj->top - 1];
}

/** 检索栈中的最小元素 */
int minStackGetMin(MinStack* obj) {
    if (obj->top == -1) {
        // 错误处理：栈为空
        return -1; // 或其他错误码/值
    }
    return obj->data[obj->top];
}

/** 释放栈 */
void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}

