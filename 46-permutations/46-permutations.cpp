class Solution {
public:
    
    set<vector<int>> s;
    vector<vector<int>> combinations;
    void generateCombos(int start, vector<int>& curr) {
        
        if(start >= curr.size()) {
            combinations.emplace_back(curr);
            return;
        };
        
        for(int ind = start; ind < curr.size(); ind++) {
            swap(curr[start], curr[ind]);
            generateCombos(start + 1, curr);
            swap(curr[start], curr[ind]);
        };
        return;
    };
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        combinations.clear();
        generateCombos(0, nums);
        return combinations;
    }
};