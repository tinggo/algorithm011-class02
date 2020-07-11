#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preBegin = 0;
        TreeNode* root = recurisiveBuildTree(preorder, preBegin, inorder, 0, inorder.size());
        return root;
    }

    TreeNode* recurisiveBuildTree(vector<int>& preorder, int& preBegin, vector<int>& inorder, int inBegin, int inLen) {
        if (inLen <= 0) return nullptr;
        int rootVal = preorder[preBegin++];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = find(inorder.begin() + inBegin, inorder.begin() + inBegin + inLen, rootVal) - inorder.begin();
        int leftLen = rootIndex - inBegin;
        int rightLen = inBegin + inLen - (rootIndex + 1);
        root->left = recurisiveBuildTree(preorder, preBegin, inorder, inBegin, leftLen);
        root->right = recurisiveBuildTree(preorder, preBegin, inorder, rootIndex + 1, rightLen);
        return root;
    }
};

int main() {
    vector<int> preorder { 3, 1, 2, 4 };
    vector<int> inorder { 1, 2, 3, 4 };
    Solution solution;
    solution.buildTree( preorder, inorder );
    return 0;
}