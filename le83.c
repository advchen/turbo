/*************************************************************************
	> File Name: le83.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 07:59:14 PM CST
 *
***********************************************************************/

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode *p = head;
    while (p->next){
        if (p->val == p->next->val){
            p->next = p->next->next;
        }else {
            p = p->next;
        }
    }
    return head;
}
