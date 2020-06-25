#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.size() == 0 ) return 0;
        int i = 1;
        for ( int j = i; j < nums.size(); ++j ) {
            if ( nums[j] != nums[j-1] ) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

int main()
{
    vector<vector<int>> cases {
        {},
        { 5 },
        { 0, 0, 0 },
        { 1, 1, 2, 2 },
        { 1, 2, 2, 4 },
        { 2, 3, 4, 5 }
    };
    Solution solution;
    for ( vector<int> &oneCase : cases ) {
        int num = solution.removeDuplicates( oneCase );
        for ( int i = 0; i < num; ++i ) {
            cout << ( i != 0 ? ", " : "" ) << oneCase[i];
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
