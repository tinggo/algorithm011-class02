#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for ( int i = grid.size() - 1; i >= 0; --i )
            for ( int j = grid[i].size() - 1; j >= 0; --j ) {
                int minNext = -1;
                if ( i + 1 < grid.size() )
                    minNext = grid[i+1][j];
                if ( j + 1 < grid[i].size() )
                    if ( minNext == -1 || grid[i][j+1] < minNext )
                        minNext = grid[i][j+1];
                if ( minNext == -1 )
                    minNext = 0;
                grid[i][j] = minNext + grid[i][j];
            }
        return grid[0][0];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid {{1,3,1},{1,5,1},{4,2,1}};
    int answer = solution.minPathSum( grid );
    cout << answer << endl;
    return 0;
}