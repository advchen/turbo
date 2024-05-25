/*************************************************************************
	> File Name: l3e25.c
	> Author: 
	> Mail: 
	> Created Time: Sat 25 May 2024 03:41:03 PM CST
 ************************************************************************/

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next; // Store the next node
        curr->next = prev; // Reverse the link
        prev = curr; // Move prev to current
        curr = nextTemp; // Move to the next node
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode* prevGroupEnd = &dummyHead;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* groupEnd = prevGroupEnd;
        for (int i = 0; i < k; i++) {
            groupEnd = groupEnd->next;
            if (!groupEnd) return dummyHead.next; 
        }
        struct ListNode* nextGroupHead = groupEnd->next;
        groupEnd->next = NULL; 
        struct ListNode* newGroupHead = reverseList(curr);
        prevGroupEnd->next = newGroupHead;
        curr->next = nextGroupHead;
        prevGroupEnd = curr;
        curr = nextGroupHead;
    }

    return dummyHead.next;
}
