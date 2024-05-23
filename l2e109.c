/*************************************************************************
	> File Name: l2e109.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 May 2024 07:26:22 PM CST
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

    `   
int getLength(struct ListNode* head) {
    int ret = 0;
    while (head != NULL) {
        ++ret, head = head->next;
    }
    return ret;
}
//求长没问题，想到了


//递归实现有问题
struct TreeNode* buildTree(struct ListNode** head, int left, int right) {
    if (left > right) {
        return NULL;
    }
    int mid = (left + right + 1) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = buildTree(head, left, mid - 1);
    root->val = (*head)->val;
    (*head) = (*head)->next;
    root->right = buildTree(head, mid + 1, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int length = getLength(head);
    return buildTree(&head, 0, length - 1);
}

