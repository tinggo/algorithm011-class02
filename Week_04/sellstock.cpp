#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prefit = 0;
        for ( int i = 0; i < prices.size(); ++i ) {
            if ( i != 0 && prices[i] > prices[i-1] )
                prefit += ( prices[i] - prices[i-1] );
        }
        return prefit;
    }
};