class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int ind = 0, len = target.size(), count = 0;
        vector<string> out;
        
        set<int> s;
        for(int i = 0; i < len; i++)
            s.insert(target[i]);
        
        for(int i = 1; i <= n; i++)
        {
            if(s.find(i) == s.end())
            {
                out.push_back("Push");
                out.push_back("Pop");
            }
            else{
                count++;
                out.push_back("Push");
            }
            
            if(count == s.size())
                return out;
        }
        
        return out;
    }
};