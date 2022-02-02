class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(s.length() < p.length())
            return {};
        
        vector<int> out;
        map<char, int> m1, m2;
        for(int i = 0; i < p.length(); i++) {
            m1[p[i]]++;
            m2[s[i]]++;
        }
        
        if(m1 == m2)
            out.push_back(0);
        
        int start = 0, end = p.length();
        while(end < s.length()) {
            m2[s[start]]--;
            if(m2[s[start]] == 0)
                m2.erase(s[start]);
            m2[s[end]]++;
            
            if(m1 == m2)
                out.push_back(end - p.length() + 1);
            start++;
            end++;
        }
        
        return out;
    }
};