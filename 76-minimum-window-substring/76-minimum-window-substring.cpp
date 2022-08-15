class Solution {
public:
    string minWindow(string s, string t) {
        
        int len1 = s.length(), len2 = t.length(), count = len2;
        unordered_map<char, int> um;
        for(auto itr : t) {
            um[itr]++;
        };
        
        int end = 0, start = 0, Min = INT_MAX;
        string out = "";
        while(end < len1) {
            
            um[s[end]]--;
            if (um[s[end]] >= 0)
                count--;
            
            end++;
            while(count == 0) {
                if ((end - start) < Min) {
                    Min = (end - start);
                    out = s.substr(start, (end - start));
                };
                um[s[start]]++;
                if (um[s[start]] > 0)
                    count++;
                start++;
            };
        };
        return out;
    };
};