#include <vector>
#include <deque>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isOneDifference( const string& str1, const string& str2 ) {
        if ( str1.size() != str2.size() ) return false;
        int difference = 0;
        for ( int i = 0; i < str1.size(); ++i ) {
            if ( str1[i] == str2[i] ) continue;
            else difference++;
            if ( difference > 1) return false;
        }
        return difference == 1;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> hashBank;
        for ( int i = 0; i < bank.size(); ++i ) hashBank[bank[i]] = false;
        hashBank[start] = false;
        deque<string> queue;
        queue.push_back(start);
        int step = 0;
        while (!queue.empty()) {
            int layerCount = queue.size();
            for ( int i = 0 ; i < layerCount; ++i ) {
                string current = queue.front();
                queue.pop_front();
                hashBank[current] = true;
                if ( current == end ) return step;
                for ( auto it : hashBank ) {
                    if (isOneDifference(current, it.first) && it.second == false) {
                        queue.push_back(it.first);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};