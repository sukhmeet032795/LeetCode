class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int l1 = s.length(), l2 = p.length();
        
        if (l2 > l1)
            return {};
        
        int index = 0, start = 0;
        unordered_map<char, int> um1, um2;
        vector<int> out;
        
        for(auto itr : p) {
            um1[itr]++;    
        };
        
        for( ; index < l2; index++) {
            um2[s[index]]++;
        };
        
        if (um1 == um2) {
            out.emplace_back(index - l2);
        };
        
        for( ; index < l1; index++, start++) {
            um2[s[start]]--;
            if (um2[s[start]] == 0)
                um2.erase(s[start]);
            
            um2[s[index]]++;
            if (um1 == um2) {
                out.emplace_back(index - l2 + 1);  
            };
        };
        
        return out;
    }
};