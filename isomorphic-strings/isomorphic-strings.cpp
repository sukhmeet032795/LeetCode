class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int len = s.length();
        map<char, char> m1, m2;
        
        for(int i = 0; i < len; i++)
        {
            if(m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end())
            {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if(m1.find(s[i]) != m1.end() && m2.find(t[i]) != m2.end())
            {
                if(m1[s[i]] != t[i] || m2[t[i]] != s[i])
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};