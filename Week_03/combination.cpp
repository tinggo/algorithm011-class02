#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        m_n = n;
        m_k = k;
        vector<vector<int>> answer;
        vector<int> selection;
        recurisiveCombine( selection, 1, answer);
        return answer;
    }

    void recurisiveCombine(vector<int>& selection, int begin, vector<vector<int>>& answer) {
        if (selection.size() >= m_k) {
            answer.push_back(selection);
            return;
        }
        for(int i = begin; i <= m_n; ++i) {
            selection.push_back(i);
            recurisiveCombine(selection, i+1, answer);
            selection.pop_back();
        }
    }

    int m_n;
    int m_k;
};

int main() {
    Solution solution;
    vector<vector<int>> combinations = solution.combine(4,2);
    for (auto combination : combinations) {
        for (int number : combination) {
            cout << number << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}