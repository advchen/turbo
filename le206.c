/*************************************************************************
	> File Name: le206.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 09:15:24 PM CST
 ************************************************************************/

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *q, newhead;
    newhead.next = NULL;
    while(head){
        q = head->next;
        head->next = newhead.next;
        newhead.next = head;
        head = q;
    }
    return newhead.next;
}
