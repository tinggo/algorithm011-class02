#include <unordered_map>
#include <vector>

using namespace std;

// BEST 哈希
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for ( int i = 0; i < nums.size(); ++i ) {
        auto find = map.find( target - nums[i] );
        if ( find != map.end() ) return vector<int> { find->second, i };
        map[nums[i]] = i;
    }
    return vector<int>();
}