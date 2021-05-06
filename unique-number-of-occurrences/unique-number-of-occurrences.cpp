class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int, int> m;
        int len = arr.size();
        
        for(int i = 0; i < len; i++)
        {
            m[arr[i]]++;
        }
        
        unordered_set<int> s;
        for(auto itr : m)
        {
            if(s.find(itr.second) != s.end())
                return false;
            s.insert(itr.second);
        }
        
        return true;
    }
};