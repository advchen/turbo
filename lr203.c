/*************************************************************************
	> File Name: lr203.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 09:05:53 PM CST
 ************************************************************************/


struct ListNode* removeElements(struct ListNode* head, int val) {
    // 创建一个虚拟头节点，以便处理头节点需要被删除的情况
    struct ListNode *head_new;
    head_new.next = head;
    struct ListNode *prev = &head_new;
    struct ListNode *current = head;

    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
        } else {
            prev = current;
        }
        current = current->next;
    }

    return head_new.next;
}
