/*************************************************************************
	> File Name: le21.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 07:41:22 PM CST
 ************************************************************************/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1){
        return list2;
    }
    if(!list2) {
        return list1;
    }
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    while (list1 != NULL && list2 != NULL){
        if (list1->val <= list2->val){
            p->next = list1;
            list1 = list1->next;
        }
        else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if (list1 != NULL){
        p->next = list1;
        p = p->next;
    }
    if (list2 != NULL){
        p->next = list2;
        p = p->next;
    }
    struct ListNode *mergedList = head->next;
    free(head);
    return mergedList;
}

