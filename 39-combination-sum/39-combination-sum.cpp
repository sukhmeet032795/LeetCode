class Solution {
public:
    
    vector<vector<int>> combinations;
    set<vector<int>> existing;
    
    void getCombinations(const vector<int>& candidates, int target, vector<int>& curr, int index) {
        
        if (target == 0) {
            combinations.emplace_back(curr);
            return;
        };
        
        for(int itr = index; itr < candidates.size(); itr++) {
            if (candidates[itr] <= target) {
                curr.push_back(candidates[itr]);
                getCombinations(candidates, target - candidates[itr], curr, itr);
                curr.pop_back();
            }
        };
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        combinations.clear();
        existing.clear();
        vector<int> curr;
        getCombinations(candidates, target, curr, 0);
        return combinations;
    }
};