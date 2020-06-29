#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// BETTER 排序+哈希
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> map;
    for ( string& str : strs ) {
        string t = str;
        sort( t.begin(), t.end() );
        map[t].push_back( str );
    }
    vector<vector<string>> answer;
    for ( auto p : map ) {
        answer.push_back(p.second);
    }
    return answer;
}

// 数组+哈希
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> map;
    for ( string& str : strs ) {
        int intKey[26] = {0};
        for ( int i = 0; i < str.size(); ++i ) {
            intKey[str[i]-'a']++;
        }
        string strKey = "";
        for ( int i = 0; i < 26; ++i ) {
            strKey += char(intKey[i] + '0');
        }
        map[strKey].push_back(str);
    }
    vector<vector<string>> answer;
    for ( auto p : map ) {
        answer.push_back(p.second);
    }
    return answer;
}