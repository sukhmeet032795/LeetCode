class Solution {
public:
    bool isAnagram(string s, string t) {
        
        auto createMap = [&](string &s) -> unordered_map<char, int> {
            unordered_map<char, int> m;
            for(auto s1 : s) {
                m[s1]++;
            }
            return m;
        };
        
        auto m1 = createMap(s), m2 = createMap(t);
        if (m1 == m2)
            return true;
        return false;
    }
};