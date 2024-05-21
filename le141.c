/*************************************************************************
	> File Name: le141.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 08:20:13 PM CST
 ************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // 快慢指针
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}
