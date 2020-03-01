/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int depth(struct TreeNode *root){
    if(root == NULL) return 0;
    int l = depth(root->left), r = depth(root->right);
    if(l == -2 || r == -2 || abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    return depth(root) >= 0;
}
