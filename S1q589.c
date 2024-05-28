/*************************************************************************
	> File Name: S1q589.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 May 2024 07:44:26 PM CST
 ************************************************************************/

#define MAX_NODE_SIZE 10000
// n叉树的后序遍历

void helper(const struct Node* root, int* res, int* pos) {
    if (NULL == root) {
        return;
    }
    for (int i = 0; i < root->numChildren; i++) {
        helper(root->children[i], res, pos);
    }
    res[(*pos)++] = root->val;
}

int* postorder(struct Node* root, int* returnSize) {
    int * res = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
    int pos = 0;
    helper(root, res, &pos);
    *returnSize = pos;
    return res;
}

// 前序遍历
#define MAX_N 10000

void helper(struct Node *root, int *res, int *pos){
    if (root == NULL) return  ;
    res[(*pos)++] = root->val;
    for (int i = 0; i < root->numChildren; i++){
        helper(root->children[i], res, pos);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * MAX_N);
    int pos = 0;
    helper(root, res, &pos);
    *returnSize = pos;
    return res;
}
