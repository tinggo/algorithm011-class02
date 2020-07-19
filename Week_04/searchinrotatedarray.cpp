#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while ( l <= r ) {
            int m = (l + r) / 2;
            if ( target == nums[m] ) return m;
            if ( target < nums[m] ) {
                if (  target >= nums[l] )
                    r = m - 1;
                else
                    l = m + 1;
            }
            else {
                if ( target <= nums[r] )
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sln;
    sln.search(vector<int>{4,5,6,7,8,1,2,3}, 8 );
    system("pause");
    return 0;
}