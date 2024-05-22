/*************************************************************************
	> File Name: le1290.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 May 2024 05:48:16 PM CST
 ************************************************************************/

int getDecimalValue(struct ListNode* head) {
    struct ListNode *p = head;
    int len = 0;
    while (p) {
        p = p->next;
        len++;
    }
    p = head;
    int n = len - 1, sum = 0;
    for (int i = 0; i < len; i++){
        sum = sum + p->val * pow (2, n);
        n--;
        p = p->next;
    }
    return sum;
}
