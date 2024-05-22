// 做过类似的，一眼就知道要怎么写
struct ListNode* trainingPlan(struct ListNode* head, int cnt) {
    struct ListNode *p, *q;
    p = head, q = head;
    
    for (int i = 0; i < cnt; i++){
        p = p->next;
    }

    while (p){
        p = p->next;
        q = q->next;
    }
    return q;
}
