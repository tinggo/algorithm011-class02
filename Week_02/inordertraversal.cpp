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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if  ( root == nullptr ) return answer;
        traverseTree( root, answer );
        return answer;
    }

    void traverseTree( TreeNode* root, vector<int>& answer ) {
        if ( root->left ) traverseTree( root->left, answer );
        answer.push_back( root->val );
        if ( root->right ) traverseTree( root->right, answer );
    }
};