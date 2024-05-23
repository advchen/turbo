/*************************************************************************
	> File Name: l2e82.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 02:22:10 PM CST
 ************************************************************************/

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;  // 如果链表为空，直接返回空指针
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));  // 创建哨兵节点
    dummy->next = head;
    struct ListNode *prev = dummy;  // 使用哨兵节点跟踪前一个不重复的节点
    struct ListNode *current = head;
    
    while (current != NULL) {
        bool is_duplicate = false;
        // 检查当前节点是否有重复
        while (current->next != NULL && current->val == current->next->val) {
            is_duplicate = true;
            current = current->next;
        }
        if (is_duplicate) {
            // 如果有重复，跳过所有重复的节点
            prev->next = current->next;
        } else {
            // 如果没有重复，将前一个不重复节点指向当前节点
            prev = prev->next;
        }
        current = current->next;
    }
    return dummy->next;
}
