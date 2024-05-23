/*************************************************************************
	> File Name: l2e92.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 03:21:38 PM CST
 ************************************************************************/

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL) return NULL;
    
    // 创建哨兵节点，简化头节点是反转部分的处理
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy;
    
    // 找到反转部分的前一个节点
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }
    
    // `start`指向需要反转的第一个节点
    struct ListNode *start = prev->next;
    // `then`指向需要反转的第一个节点的下一个节点
    struct ListNode *then = start->next;
    
    // 进行反转
    for (int i = 0; i < right - left; ++i) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }
    
    // 返回新的头节点
    return dummy->next;
}
