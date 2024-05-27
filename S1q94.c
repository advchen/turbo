/*************************************************************************
        > File Name: S1q94.c
        > Author:
        > Mail:
        > Created Time: Mon 27 May 2024 07:06:36 PM CST
 ************************************************************************/
//后序遍历
void postorder(struct TreeNode *root, int *res, int *returnSize){
    if (!root) return ;
    postorder(root->left, res, returnSize);
    postorder(root->right, res, returnSize);
    res[(*returnSize)++] = root->val;
    return ;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 101);
    *returnSize = 0;
    postorder(root, res, returnSize);
    return res;
}


//前序遍历
void preorder(struct TreeNode *root, int *res, int *returnSize){
    if (!root) return ;
    res[(*returnSize)++] = root->val;
    preorder(root->left, res, returnSize);
    preorder(root->right, res, returnSize);
    return ;
}



int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 101);
    *returnSize = 0;
    preorder(root, res, returnSize);
    return res;
}


//中序遍历
 void inorder(struct TreeNode* root, int* res, int* resSize) {
    if (!root) {
        return;
    }
    inorder(root->left, res, resSize);
    res[(*resSize)++] = root->val;
    inorder(root->right, res, resSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * 501);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}
