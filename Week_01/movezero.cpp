#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( nums[i] != 0 )
            {
                nums[j] = nums[i];
                if ( i != j )
                    nums[i] = 0;
                j++;
            }
        }
    }
};

int main() {
    vector<int> nums { 0, 1, 3, 0, 5 };
    Solution solution;
    solution.moveZeroes( nums );
    for ( int i : nums ) {
        cout << i << " ";
    }
    cout<< endl;
    system( "pause" );
    return 0;
}

