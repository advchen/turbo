/*************************************************************************
	> File Name: lcr123.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 May 2024 06:07:17 PM CST
 ************************************************************************/

 int* reverseBookList(struct ListNode* head, int* returnSize) {
    int *p = (int *)calloc(sizeof(int), 10000);
    int *q = (int *)calloc(sizeof(int), 10000);
    struct ListNode *l = head;
    int len = 0;
    while(l){
        p[len++] = l->val;
        l = l->next;
    }
    int k = len -1;
    for (int i = 0; i < len; i++){
        q[i] = p[k--];
    }
    *returnSize = len;
    free(p);
    return q;
}
