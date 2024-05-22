/*************************************************************************
	> File Name: BINode.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 May 2024 08:06:18 PM CST
 ************************************************************************/

// 中序遍历函数，用于将二叉搜索树转换为单向链表
void inorder(struct TreeNode* node, struct TreeNode** prev) {
    if (node == NULL) return;

    // 递归遍历左子树
    inorder(node->left, prev);

    // 当前节点的左子节点设为 NULL
    node->left = NULL;

    // 如果前一个节点不为空，则将前一个节点的右子节点指向当前节点
    if (*prev != NULL) {
        (*prev)->right = node;
    }

    // 更新前一个节点为当前节点
    *prev = node;

    // 递归遍历右子树
    inorder(node->right, prev);
}

// 主函数，转换二叉搜索树为单向链表
struct TreeNode* convertBiNode(struct TreeNode* root) {
    // 创建一个哑节点，其右子节点将作为链表的头节点
    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    dummy->right = NULL; // 初始化 dummy 节点的 right 指针为 NULL
    struct TreeNode* prev = dummy;

    // 中序遍历转换
    inorder(root, &prev);

    // 链表的头节点是 dummy 的右子节点
    struct TreeNode* head = dummy->right;
    free(dummy);  // 释放哑节点
    return head;
}
