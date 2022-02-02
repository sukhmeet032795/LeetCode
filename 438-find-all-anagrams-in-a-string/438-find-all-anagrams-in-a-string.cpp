class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(s.length() < p.length())
            return {};
        
        vector<int> out;
        map<char, int> m1, m2;
        for(int i = 0; i < p.length(); i++) {
            m1[p[i]]++;
        }
        
        int start = 0, end = 0, count = 0;
        while(end < s.length()) {
            
            if(m1.find(s[end]) == m1.end()) {
                end++;
                start = end;
                count = 0;
                m2.clear();
                continue;
            }
            
            m2[s[end]]++;
            count++;
            
            if(count == p.length() && m1 == m2)
                out.push_back(end - p.length() + 1);
            
            while(count >= p.length()) {
                m2[s[start]]--;
                if(m2[s[start]] == 0)
                    m2.erase(s[start]);
                start++;
                count--;
            }
            end++;
        }
        
        return out;
    }
};