#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool prompt = false;
        for ( int i = digits.size() - 1; i >= 0; i-- ) {
            int digit = digits[i];
            if ( i == digits.size() - 1 || prompt )
                digit++;
            prompt = (digit / 10) != 0;
            digits[i] = digit % 10;
            if ( prompt && i == 0 ) {
                digits.insert( digits.begin(), 1 );
            }
        }
        return digits;
    }
};

int main() {
    vector<int> testCase1 { 9,9,9,9 };
    vector<int> testCase2 { 0 };
    vector<int> testCase3 { 1,2,3,4 };

    Solution solution;
    vector<int> answer;
    answer = solution.plusOne( testCase1 );
    for ( int digit : answer )
        cout << digit << " ";
    cout<<endl;
    answer = solution.plusOne( testCase2 );
    for ( int digit : answer )
        cout << digit << " ";
    cout<<endl;
    answer = solution.plusOne( testCase3 );
    for ( int digit : answer )
        cout << digit << " ";
    cout<<endl;
    system("pause");
    return 0;
}