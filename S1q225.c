/*************************************************************************
	> File Name: S1q225.c
	> Author: 
	> Mail: 
	> Created Time: Sun 26 May 2024 09:14:24 PM CST
 ************************************************************************/

#define LEN 20
typedef struct queue {
    int *data;
    int head;
    int rear;
    int size;
} Queue;

typedef struct {
    Queue *queue1, *queue2;
} MyStack;

Queue *initQueue(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->data = (int *)malloc(k * sizeof(int));
    obj->head = -1;
    obj->rear = -1;
    obj->size = k;
    return obj;
}

void enQueue(Queue *obj, int e) {
    if (obj->head == -1) {
        obj->head = 0;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->data[obj->rear] = e;
}

int deQueue(Queue *obj) {
    int a = obj->data[obj->head];
    if (obj->head == obj->rear) {
        obj->rear = -1;
        obj->head = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;
    return a;
}

int isEmpty(Queue *obj) {
    return obj->head == -1;
}

MyStack *myStackCreate() {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue1 = initQueue(LEN);
    obj->queue2 = initQueue(LEN);
    return obj;
}

void myStackPush(MyStack *obj, int x) {
    if (isEmpty(obj->queue1)) {
        enQueue(obj->queue2, x);
    } else {
        enQueue(obj->queue1, x);
    }
}

int myStackPop(MyStack *obj) {
    if (isEmpty(obj->queue1)) {
        while (obj->queue2->head != obj->queue2->rear) {
            enQueue(obj->queue1, deQueue(obj->queue2));
        }
        return deQueue(obj->queue2);
    }
    while (obj->queue1->head != obj->queue1->rear) {
        enQueue(obj->queue2, deQueue(obj->queue1));
    }
    return deQueue(obj->queue1);
}

int myStackTop(MyStack *obj) {
    if (isEmpty(obj->queue1)) {
        return obj->queue2->data[obj->queue2->rear];
    }
    return obj->queue1->data[obj->queue1->rear];
}

bool myStackEmpty(MyStack *obj) {
    if (obj->queue1->head == -1 && obj->queue2->head == -1) {
        return true;
    }
    return false;
}

void myStackFree(MyStack *obj) {
    free(obj->queue1->data);
    obj->queue1->data = NULL;
    free(obj->queue1);
    obj->queue1 = NULL;
    free(obj->queue2->data);
    obj->queue2->data = NULL;
    free(obj->queue2);
    obj->queue2 = NULL;
    free(obj);
    obj = NULL;
}
