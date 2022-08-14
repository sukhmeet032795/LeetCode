class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int start = 0, end = 0, len = s.length(), Max = 0;
        unordered_set<char> m;
        
        while(end < len) {
            if (m.find(s[end]) != m.end()) {
                m.erase(s[start++]);
            } else {
                m.insert(s[end++]);
                Max = max(Max, end - start);
            };
        };
        return Max;
    }
};