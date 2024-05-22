/*************************************************************************
	> File Name: le876.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 May 2024 05:39:19 PM CST
 ************************************************************************/
//自己写的
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *p = head;
    int len = 0;
    while (p){
        p = p->next;
        len++;
    }
    if (len <= 1) return head;
    p = head;
    if (len % 2 == 0){
        for (int i = 0; i < len / 2 - 1; i++){
            p = p->next;
        }
    }else {
        for (int i = 0; i < len / 2 - 1; i++){
            p = p->next;
        }
    }
    return p->next;
}

//答案确是很好
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head) {
    //创建两个指针slow和fast,slow一次走一步,fast一次走两步
    ListNode* slow, *fast;
    slow = fast = head;
    while( fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
