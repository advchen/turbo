/*************************************************************************
	> File Name: l2e142.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 10:07:59 PM CST
 ************************************************************************/

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (true) {
        if (fast == NULL || fast->next == NULL) return NULL;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}
