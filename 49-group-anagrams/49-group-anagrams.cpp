class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> out;
        map<string, vector<string>> m;
        int size = strs.size();
        
        if(size == 0)
            return {};
        
        for(int i = 0; i < size; i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            
            m[tmp].push_back(strs[i]);
        };
        
        for(auto itr : m)
        {
            out.push_back(itr.second);
        };
        
        return out;
    }
};