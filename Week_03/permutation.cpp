#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        recurisivePermute( nums, 0, answer );
        return answer;
    }

    void recurisivePermute(vector<int>& nums, int begin, vector<vector<int>>& answer) {
        if ( begin == nums.size() - 1 ) {
            answer.push_back(nums);
            return;
        }
        for ( int i = begin; i < nums.size(); ++i ) {
            swap( nums[begin], nums[i] );
            recurisivePermute( nums, begin + 1, answer );
            swap( nums[begin], nums[i] );
        }
    }
};

int main() {
    vector<int> nums { 1, 2, 3 };
    Solution solution;
    vector<vector<int>> answers = solution.permute(nums);
    for ( vector<int>& oneAnswer : answers ) {
        for ( int number : oneAnswer)
            cout << number << " ";
        cout << endl;
    }
    system( "pause" );
    return 0;
}