/*************************************************************************
	> File Name: l2e382.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 May 2024 09:29:15 PM CST
 ************************************************************************/

typedef struct {
    int *arr;
    int length;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution * obj = (Solution *)malloc(sizeof(Solution));
    if (obj == NULL) return NULL;
    obj->length = 0;
    struct ListNode * node = head;

    while (node) {
        node = node->next;
        obj->length++;
    }
    obj->arr = (int *)malloc(sizeof(int) * obj->length);
    if (obj->arr == NULL) return NULL;
    node = head;
    for (int i = 0; i < obj->length; i++) {
        obj->arr[i] = node->val;
        node = node->next;
    }
    return obj;
}

int solutionGetRandom(Solution* obj) {
    return obj->arr[rand() % obj->length];
}

void solutionFree(Solution* obj) {
    free(obj->arr);
    free(obj);
}
