#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        map<int,int> booking;
        for ( int i = 0; i < nums.size(); ++i ) {
            int a = nums[i];
            int b = target - a;
            auto findIt = booking.find( b );
            if ( findIt != booking.end() ) {
                answer.push_back( i );
                answer.push_back( findIt->second );
                break;
            }
            else {
                booking[a] = i;
            }
        }
        sort( answer.begin(), answer.end() );
        return answer;
    }
};

int main() {
    vector<int> nums { 2, 7, 11, 15 };
    Solution solution;
    vector<int> result = solution.twoSum( nums, 9 );
    for ( int n : result ) {
        cout << n << " ";
    }
    cout<<endl;
    system("pause");
    return 0;
}