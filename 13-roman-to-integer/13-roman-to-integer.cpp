class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                      {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = m[s[0]];
        for(int i = 1; i < s.length(); i++) {
            ans += m[s[i]];
            
            if ((s[i] == 'V' || s[i] == 'X') && s[i-1] == 'I') { ans -= 2; }
            if ((s[i] == 'L' || s[i] == 'C') && s[i-1] == 'X') { ans -= 20; }
            if ((s[i] == 'D' || s[i] == 'M') && s[i-1] == 'C') { ans -= 200; }
        };
        return ans;
    }
};