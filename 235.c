struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    //p指向较小的节点
    if(p->val>q->val)
    {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }
    //root的值不再位于二者中间的时候，返回节点即为所求
    while(root->val < p->val || root->val > q->val)
    {
        if(root->val < p->val)root = root->right;
        else if (root->val > q->val)root = root->left;
        else return root;
    }
    return root;
}
