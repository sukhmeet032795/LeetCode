class Solution {
public:
    int findLUSlength(string a, string b) {
        
        if(a == b)
            return -1;
        
        if(a != b)
            return max(a.length(), b.length());
        
        unordered_map<char, int> m1, m2;
        for(int i = 0; i < a.length(); i++)
            m1[a[i]]++;
        
        for(int i = 0; i < b.length(); i++)
            m2[b[i]]++;
        
        int count1 = 0, count2 = 0;
        for(auto itr : m1)
        {
            if(m2.find(itr.first) == m2.end())
            {
                count1  += itr.second;
            }
            else
            {
                count1 += abs(itr.second - m2[itr.first]);
            }
        }
        
        for(auto itr : m2)
        {
            if(m1.find(itr.first) == m1.end())
            {
                count2  += itr.second;
            }
            else
            {
                count2 += abs(itr.second - m1[itr.first]);
            }
        }
        
        return max(count1, count2);
    }
};