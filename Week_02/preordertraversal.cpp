#include <vector>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        if (!root) return answer;
        traversalTree(root, answer);
        return answer;
    }

    void traversalTree(TreeNode* root, vector<int>& answer ) {
        answer.push_back(root->val);
        if (root->left) traversalTree(root->left, answer);
        if (root->right) traversalTree(root->right, answer);
    }
};