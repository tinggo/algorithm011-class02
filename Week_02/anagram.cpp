#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 暴力法
bool isAnagram(string s, string t) {
    sort( s.begin(), s.end() );
    sort( t.begin(), t.end() );
    return s == t;
}

// 哈希法
bool isAnagram(string s, string t) {
    unordered_map<char,int> map;
    for ( int i = 0; i < s.size(); ++i ) {
        char c = s[i];
        auto findResult = map.find(c);
        if ( findResult != map.end() )
            findResult->second++;
        else
            map.insert( {c, 1} );
    }
    for ( int i = 0; i < t.size(); ++i ) {
        char c = t[i];
        auto findResult = map.find(c);
        if ( findResult != map.end() ) {
            findResult->second--;
            if ( findResult->second == 0 )
                map.erase( findResult );
        }
        else
            return false;
    }
    return map.size() == 0;
}

// BEST，数组法
bool isAnagram(string s, string t) {
    if ( s.size() != t.size() ) return false;
    int map[26] = {0};
    for ( int i = 0; i < s.size(); ++i ) map[s[i] - 'a']++;
    for ( int i = 0; i < t.size(); ++i ) map[t[i] - 'a']--;
    for ( int i = 0; i < 26; ++i ) if ( map[i] ) return false;
    return true;
}