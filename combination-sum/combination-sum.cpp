class Solution {
public:
    
    set<vector<int>> sNums;
    vector<vector<int>> out;
    
    void getCombinations(vector<int> &candidates, vector<int> arr, int currVal)
    {
        if(currVal < 0)
            return;
        
        if(currVal == 0)
        {
            sort(arr.begin(), arr.end());
            if(sNums.find(arr) == sNums.end())
            {
                out.push_back(arr);
                sNums.insert(arr);
            }
            return;
        }
        
        for(int i = 0; i < candidates.size(); i++)
        {
            arr.push_back(candidates[i]);
            getCombinations(candidates, arr, currVal - candidates[i]);
            arr.pop_back();
        };
        
        return;
    };
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sNums.clear();
        out.clear();
        
        vector<int> arr;
        getCombinations(candidates, arr, target);
        
        return out;
    }
};