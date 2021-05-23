class Solution {
public:
    string customSortString(string order, string str) {
        
        map<char, int> m;
        int l1 = order.length(), l2 = str.length();
        
        for(int i = 0; i < l2; i++)
            m[str[i]]++;
        
        for(int i = 0; i < l1; i++)
            m[order[i]]--;
        
        string out = "";
        
        for(int i = 0; i < l1; i++)
        {
            if(m[order[i]] < 0)
                continue;
            out += order[i];
            int len = m[order[i]];
            for(int j = 0; j < len; j++)
            {
                out += order[i];
            }
            m[order[i]] = 0;
        }
        
        for(auto itr : m)
        {
            for(int i = 0; i < itr.second; i++)
            {
                out += itr.first;
            };
        };
        
        return out;
    }
};