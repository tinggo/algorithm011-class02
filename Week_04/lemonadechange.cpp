#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m5 = 0, m10 = 0;
        for ( auto bill : bills ) {
            switch (bill) {
            case 5:
                m5++;
                continue;
            case 10:
                m5--;
                m10++;
                break;
            case 20:
                if ( m10 > 0 ) {
                    m10--;
                    m5--;
                }
                else {
                    m5 = m5 - 3;
                }
                break;
            }
            if ( m5 < 0 )
                return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    solution.lemonadeChange(vector<int> {5,5,5,10,5,5,10,20,20,20});
    return 0;
}