class Solution {
public:
    vector<vector<int>> combinations;
    void generateCombos(int start, const int& n, const int& k, vector<int>& curr) {
        
        if (curr.size() == k) {
            combinations.emplace_back(curr);
            return;
        };
        
        for(int ind = start; ind <= n; ind++) {
            curr.emplace_back(ind);
            generateCombos(ind + 1, n, k, curr);
            curr.pop_back();
        };
        return;
    };
    
    vector<vector<int>> combine(int n, int k) {
        combinations.clear();
        vector<int> curr;
        generateCombos(1, n, k, curr);
        return combinations;
    };
};