/*************************************************************************
	> File Name: l3e23.c
	> Author: 
	> Mail: 
	> Created Time: Sat 25 May 2024 02:56:55 PM CST
 ************************************************************************/

struct ListNode* mergeTwoLists(struct ListNode *a, struct ListNode *b) {
    if (!a) return b;
    if (!b) return a;
    struct ListNode head;
    struct ListNode *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
        if (aPtr->val < bPtr->val) {
            tail->next = aPtr;
            aPtr = aPtr->next;
        } else {
            tail->next = bPtr;
            bPtr = bPtr->next;
        }
        tail = tail->next;
    }
    tail->next = aPtr ? aPtr : bPtr;
    return head.next;
}

struct ListNode* merge(struct ListNode** lists, int l, int r) {
    if (l == r) return lists[l];
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    struct ListNode* left = merge(lists, l, mid);
    struct ListNode* right = merge(lists, mid + 1, r);
    return mergeTwoLists(left, right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    return merge(lists, 0, listsSize - 1);
}
