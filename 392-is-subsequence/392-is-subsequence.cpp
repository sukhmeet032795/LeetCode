class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int sInd = 0;
        for(auto t1 : t) {
            if (sInd == s.length())
                return true;
            
            if (t1 == s[sInd]) {
                sInd++;
            };
        }
        
        return (sInd == s.length());
    }
};