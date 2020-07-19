#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool jump( vector<int>& nums, int index ) {
        if ( index >= nums.size() - 1 )
            return true;
        int strip = nums[index];
        if ( strip == 0 )
            return false;

        for ( int i = 1; i <= strip; ++i )
            if ( jump( nums, index + i ) )
                return true;

        return false;
    }

    bool canJump(vector<int>& nums) {
        return jump( nums, 0 );
    }
};

int main() {
    Solution solution;
    bool result = solution.canJump( vector<int> { 2, 5, 0, 0 } );
    cout << result << endl;
    system("pause");
    return 0;
}