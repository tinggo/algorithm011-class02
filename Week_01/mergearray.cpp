#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = nums1.size();
        int i = 0, j = 0;
        while ( j < n ) {
            if ( nums1[i] > nums2[j] || i == m ) {
                nums1.insert( nums1.begin() + i, nums2[j] );
                m++, j++;
            }
            if ( i < m  )
                i++;
        }
        nums1.resize( s );
    }
};

int main() {
    vector<int> nums1 { 0,0,0,0,0,0,0,0 };
    vector<int> nums2 { 2, 5, 6 };
    Solution solution;
    solution.merge( nums1, 3, nums2, 3 );
    for ( int num : nums1 )
        cout << num << " ";
    cout << endl;
    system( "pause" );
    return 0;
}