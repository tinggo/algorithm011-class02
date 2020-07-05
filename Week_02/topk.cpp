#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for ( int& num : nums ) umap[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        for ( auto it : umap )
            if (pq.size() >= k) {
                if (it.second > pq.top().first) {
                    pq.pop();
                    pq.push(pair<int,int>(it.second, it.first));
                }
            }
            else
                pq.push(pair<int,int>(it.second, it.first));
        vector<int> answer;
        while (pq.size()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};

