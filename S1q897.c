/*************************************************************************
	> File Name: S1q897.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 08:24:20 PM CST
 ************************************************************************/

void inorder(struct TreeNode *root, int *pos, int *ret) {
    if (root == NULL) return;
    inorder(root->left, pos, ret);      
    ret[(*pos)++] = root->val;           
    inorder(root->right, pos, ret);    
}

struct TreeNode *getnewnode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    int pos = 0;
    int *ret = (int *)malloc(sizeof(int) * 100);  
    inorder(root, &pos, ret);

    struct TreeNode *dummy = getnewnode(0);  // 创建一个虚拟节点以简化新树的构建
    struct TreeNode *current = dummy;

    for (int i = 0; i < pos; i++) {
        current->right = getnewnode(ret[i]);
        current = current->right;
    }

    struct TreeNode *result = dummy->right; 
    free(dummy);
    free(ret);
    
    return result;
}
