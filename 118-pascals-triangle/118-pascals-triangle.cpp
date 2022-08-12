class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> out;
        out.push_back({1});
        
        for(int i = 1; i < numRows; i++) {
            vector<int> tmp;
            for(int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    tmp.emplace_back(1);
                } else {
                    tmp.emplace_back(out[i-1][j-1] + out[i-1][j]);
                }
            };
            out.emplace_back(tmp);
        };
        
        return out;
    }
};