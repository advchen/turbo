/*************************************************************************
	> File Name: l2e143.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 May 2024 08:05:08 PM CST
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// 重新排列链表的函数
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // 使用快慢指针法找到链表的中间节点
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 翻转链表的后半部分
    struct ListNode* second = reverseList(slow->next);
    slow->next = NULL;

    // 交替合并两个部分
    struct ListNode* first = head;
    while (second != NULL) {
        struct ListNode* temp1 = first->next;
        struct ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

