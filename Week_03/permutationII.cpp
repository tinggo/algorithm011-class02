#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> answer;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        recurisive(nums, 0, nums.size() - 1);
        return answer;
    }

    void recurisive(vector<int> nums, int left, int right) {
        if (left == right) {
            answer.push_back(nums);
            return;
        }
        for (int i = left; i <= right; ++i) {
            if (i != left && nums[i] == nums[left]) continue;
            swap(nums[left], nums[i]);
            recurisive(nums, left + 1, right);
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> answer = solution.permuteUnique(vector<int>{2,2,1,1});
    for ( auto& v : answer ) {
        for ( int n : v )
            cout << n << " ";
        cout << endl;
    }
    system("pause");
    return 0;
}