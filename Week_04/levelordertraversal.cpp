#include <deque>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answers;
        if ( root == nullptr )
            return answers;
        deque<TreeNode*> queue;
        answers.push_back(vector<int>{root->val});
        queue.push_back(root);
        while(!queue.empty()) {
            int levelSize = queue.size();
            vector<int> answer;
            for ( int i = 0; i < levelSize; ++i ) {
                TreeNode* node = queue.front();
                queue.pop_front();
                if ( node->left ) {
                    answer.push_back(node->left->val);
                    queue.push_back(node->left);
                }
                if ( node->right ) {
                    answer.push_back(node->right->val);
                    queue.push_back(node->right);
                }
            }
            if (!answer.empty())
                answers.push_back(answer);
        }
        return answers;
    }
};