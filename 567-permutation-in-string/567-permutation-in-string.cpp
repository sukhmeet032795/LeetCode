class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int l1 = s1.length(), l2 = s2.length();
        if (l1 > l2)
            return false;
        
        unordered_map<char, int> um1, um2;
        for(auto s : s1) {
            um1[s]++;    
        };
        
        int index = 0, start = 0;
        for( ; index < l1; index++) {
            um2[s2[index]]++;
        };
        
        if (um1 == um2)
            return true;
        
        for( ; index < l2; index++, start++ ) {
            um2[s2[start]]--;
            if (um2[s2[start]] == 0) { um2.erase(s2[start]); }
            
            um2[s2[index]]++;
            
            if (um1 == um2)
                return true;
        };
        
        return false;
    }
};