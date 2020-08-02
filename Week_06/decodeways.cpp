#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if ( len == 0 ) return 0;
        if ( s[0] == '0' ) return 0;
        if ( len == 1 ) return 1;
        if ( len == 2 )
        {
            int num = atoi(s.c_str());
            return ( num <= 26 && num % 10 != 0 ) ? 2 : 1;
        }
        return numDecodings( s.substr( 1, len - 1 ) ) + numDecodings( s.substr( 2, len - 2 ) );
    }
};

int main() {
    Solution solution;
    int answer = solution.numDecodings( "01" );
    cout << answer << endl;
    return 0;
}