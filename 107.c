/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int getdepth(struct TreeNode *root){
    if(root == NULL) return 0;
    int l = getdepth(root->left), r = getdepth(root->right);
    return (l > r ? l : r) + 1;
}
void getcnt(struct TreeNode *root, int k, int *cnt){
    if(root == NULL) return;
    cnt[k]++;
    getcnt(root->left, k - 1, cnt);
    getcnt(root->right, k - 1, cnt);
    return;
}
void getresult(struct TreeNode *root, int k, int *cnt, int **ret){
    if(root == NULL) return;
    ret[k][cnt[k]++] = root->val;
    getresult(root->left, k - 1, cnt, ret);
    getresult(root->right, k - 1, cnt, ret);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
        int n = getdepth(root);
        int **ret = (int **)malloc(sizeof(int *) * n);
        int *cnt = (int *)calloc(n, sizeof(int));
        getcnt(root, n - 1, cnt);
        for(int i = 0; i < n; i++){
            ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
            cnt[i] = 0;
        }
        getresult(root, n - 1, cnt, ret);
        *returnSize = n;
        *returnColumnSizes = cnt;
        return ret;
}
