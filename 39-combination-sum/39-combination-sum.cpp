class Solution {
public:
    
    vector<vector<int>> combos;
    void getCombinations(vector<int>& candidates, int target, vector<int>& curr, int index) {
        
        if (target == 0) {
            combos.emplace_back(curr);
            return;
        };
        
        for(int i = index; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                curr.emplace_back(candidates[i]);
                getCombinations(candidates, target - candidates[i], curr, i);
                curr.pop_back();
            };
        };
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        combos.clear();
        vector<int> curr;
        getCombinations(candidates, target, curr, 0);
        return combos;
    }
};