/*************************************************************************
	> File Name: le160.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 08:40:18 PM CST
 ************************************************************************/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == headB) return headA;
    struct ListNode *p = headA;
    struct ListNode *q = headB;
    while (p != q){
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }
    return p;
}
