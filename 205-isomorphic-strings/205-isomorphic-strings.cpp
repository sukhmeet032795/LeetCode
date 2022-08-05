class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> u1, u2;
        for(int i = 0; i < s.length(); i++) {
            if (u1.find(s[i]) == u1.end() && u2.find(t[i]) == u2.end()) {
                u1[s[i]] = t[i];
                u2[t[i]] = s[i];
            }
            else if (u1.find(s[i]) != u1.end() && u1[s[i]] != t[i]) { return false; }
            else if (u2.find(t[i]) != u2.end() && u2[t[i]] != s[i]) { return false; }
        };
        
        return true;
    }
};