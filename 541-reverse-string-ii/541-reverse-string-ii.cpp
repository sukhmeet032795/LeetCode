class Solution {
public:
    string reverseStr(string s, int k) {
        
        if (k == 1) return s;
        
        int len = s.length();
        for(int i = 0; i < len; i += (k*2)) {
            if ((i + k) >= len) {
                reverse(s.begin() + i, s.end());
                return s;
            }
            reverse(s.begin() + i, s.begin() + (i + k));
        }
        return s;
    }
};