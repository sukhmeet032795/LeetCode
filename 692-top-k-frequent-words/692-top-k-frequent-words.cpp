class Solution {
public:
    
    struct customSort{
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
            if (p1.second == p2.second) {
                return p1.first > p2.first;
            };
            return p1.second < p2.second;
        };
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> um;
        for(auto word : words) {
            um[word]++;
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, customSort> p;
        for(auto word: um) {
            p.push(make_pair(word.first, word.second));
        };
        
        vector<string> out;
        while(k--) {
            auto tmp = p.top();
            p.pop();
            out.emplace_back(tmp.first);
        };
        return out;
    }
};