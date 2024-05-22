/*************************************************************************
	> File Name: le2.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 May 2024 09:25:56 PM CST
 ************************************************************************/

struct ListNode* newListNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    
    // 使用哑节点简化结果链表的处理
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *current = &dummy;
    int carry = 0;

    // 遍历两个链表
    while (p1 != NULL || p2 != NULL || carry) {
        int x = (p1 != NULL) ? p1->val : 0;
        int y = (p2 != NULL) ? p2->val : 0;
        int sum = carry + x + y;

        // 更新进位
        carry = sum / 10;
        // 创建新节点并连接到结果链表
        current->next = newListNode(sum % 10);
        current = current->next;

        // 移动到下一个节点
        if (p1 != NULL) p1 = p1->next;
        if (p2 != NULL) p2 = p2->next;
    }

    struct ListNode* result = dummy.next;
    free(dummy);
    return result;
}
