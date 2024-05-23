/*************************************************************************
	> File Name: l2e86.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 02:46:30 PM CST
 ************************************************************************/

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l = head, *l1 = p, *l2 = q;
    while (l){
        if (l->val < x){
            p->next = l;
            p = p->next;
        }else {
            q->next = l;
            q = q->next;
        }
        l = l->next;
    }
    q->next = NULL;
    p->next = l2->next;
    return l1->next;
}
