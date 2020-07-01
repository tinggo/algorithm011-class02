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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> answer;
        if (root){
            vector<Node*> level {root};
            traversal(level, answer);
        }
        return answer;
    }

    void traversal(vector<Node*> level, vector<vector<int>>& answer) {
        vector<int> levelAnswer;
        vector<Node*> nextLevel;
        for (Node* node : level) {
            levelAnswer.push_back(node->val);
            for(Node* node2 : node->children)
                nextLevel.push_back(node2);
        }
        if (levelAnswer.size()) answer.push_back(levelAnswer);
        if (nextLevel.size()) traversal(nextLevel, answer);
    }
};