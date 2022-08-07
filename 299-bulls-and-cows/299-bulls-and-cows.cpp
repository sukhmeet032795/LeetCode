class Solution {
public:
    string getHint(string secret, string guess) {
        
        int xS = 0, yS = 0;
        unordered_map<char, int> m;
        
        for(int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                xS++;
                secret[i] = guess[i] = '.';
            };
        };
        
        for(auto s : secret) {
            if (s != '.') {
                m[s]++;
            }
        };
        
        for(auto g : guess) {
            if (g != '.') {
                if (m.find(g) != m.end()) {
                    m[g]--;
                    if (m[g] == 0)
                        m.erase(g);
                    yS++;
                };
            };
        };
        
        stringstream ss;
        ss << xS << "A" << yS << "B";
        
        return ss.str();
    }
};