class Solution {
public:
    
    struct customSort{
        bool operator()(const pair<int, string> &p1, const pair<int, string> &p2) {
            if (p1.first == p2.first) {
                return p1.second > p2.second;
            };
            return p1.first < p2.first;
        };
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, customSort> p;
        unordered_map<string, int> um;
        
        for(auto word : words) {
            um[word]++;
        };
        
        for(auto itr : um) {
            p.push(make_pair(itr.second, itr.first));
        };
        
        um.clear();
        
        vector<string> out;
        int ind = 0;
        while(ind++ < k) {
            out.push_back(p.top().second);
            p.pop();
        };
        
        return out;
    }
};