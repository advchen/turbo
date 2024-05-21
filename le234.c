/*************************************************************************
	> File Name: le234.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 May 2024 09:43:28 PM CST
 ************************************************************************/

bool isPalindrome(struct ListNode* head) {
    if (!head) return true;
    
    int leng = 0;
    struct ListNode* temp = head;
    while (temp) {
        leng++;
        temp = temp->next;
    }
    
    int arr[leng];
    temp = head;
    for (int i = 0; i < leng; i++) {
        arr[i] = temp->val;
        temp = temp->next;
    }
    
    for (int i = 0; i < leng / 2; i++) {
        if (arr[i] != arr[leng - 1 - i]) {
            return false;
        }
    }
    
    return true;
}
