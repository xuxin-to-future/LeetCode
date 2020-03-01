/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    if(!root->left && !root->right) return 1;
    if(!root->left || !root->right){
        return minDepth(root->left ? root->left : root->right) + 1;
    } 
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}
