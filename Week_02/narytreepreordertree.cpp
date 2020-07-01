#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> answer;
        if (!root) return answer;
        traversalTree(root, answer);
        return answer;
    }

    void traversalTree(Node* root, vector<int>& answer) {
        answer.push_back(root->val);
        for (Node* child : root->children) {
            traversalTree(child, answer);
        }
    }
};