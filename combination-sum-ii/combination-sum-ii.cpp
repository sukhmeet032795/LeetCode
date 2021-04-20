class Solution {
public:
    
    set<vector<int>> sNums;
    vector<vector<int>> out;
    
    void getCombinations(vector<int> &candidates, vector<int> &arr, int index, int &currVal)
    {
        if(currVal < 0 || (currVal != 0 && index >= candidates.size()))
            return;
        
        if(currVal == 0)
        {
            if(sNums.find(arr) == sNums.end())
            {
                out.push_back(arr);
                sNums.insert(arr);
            }
            return;
        }
        
        for(int i = index; i < candidates.size(); i++)
        {
            arr.push_back(candidates[i]);
            currVal -= candidates[i];
            getCombinations(candidates, arr, i+1, currVal);
            currVal += candidates[i];
            arr.pop_back();
        };
        
        return;
    };
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sNums.clear();
        out.clear();
        sort(candidates.begin(), candidates.end());
        
        if(target == 0)
            return {{}};
        
        vector<int> arr;
        getCombinations(candidates, arr, 0, target);
        
        return out;
    }
};