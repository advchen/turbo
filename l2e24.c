/*************************************************************************
	> File Name: l2e24.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 01:18:40 PM CST
 ************************************************************************/

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode *p = head;
    while (p != NULL && p->next !=  NULL){
        int va = p->val;
        p->val = p->next->val;
        p->next->val = va;
        p = p->next->next;
    }
    return head;
}
