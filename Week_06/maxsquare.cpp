#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int getDpValue(vector<vector<int>> &dp, int i, int j) {
        int row = dp.size();
        int col = dp[0].size();
        if ( i >= 0 && i < row && j >=0 && j < col )
            return dp[i][j];
        return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        int answer = 0;
        for ( int i = 0; i < row; ++i ) {
            for ( int j = 0; j < col; ++j ) {
                if ( matrix[i][j] == '0')
                    dp[i][j] = 0;
                else {
                    int currentMin = getDpValue(dp, i - 1, j);
                    currentMin = min(currentMin, getDpValue(dp, i - 1, j - 1));
                    currentMin = min(currentMin, getDpValue(dp, i, j - 1));
                    dp[i][j] = currentMin + 1;
                    if (dp[i][j] > answer)
                        answer = dp[i][j];
                }
            }
        }
        return answer * answer;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix {{'1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','0'},{'1','1','1','1','1','0','0','0'},{'0','1','1','1','1','0','0','0'}};
    int answer = solution.maximalSquare( matrix );
    cout << answer << endl;
    return 0;
}