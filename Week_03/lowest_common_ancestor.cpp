struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( root == nullptr || root->val == p->val || root->val == q->val ) {
            return root;
        }
        TreeNode *l = lowestCommonAncestor( root->left, p, q );
        TreeNode *r = lowestCommonAncestor( root->right, p, q );
        if (l==nullptr) return r;
        if (r==nullptr) return l;
        if (l && r) return root;
        return nullptr;
    }
};