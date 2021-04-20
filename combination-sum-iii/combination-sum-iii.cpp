class Solution {
public:
    
    set<vector<int>> sNums;
    vector<vector<int>> out;
    vector<int> candidates = {1,2,3,4,5,6,7,8,9};
    
    void getCombinations(vector<int> &arr, int index, int &currVal, int &size, int &k, int &ck)
    {
        if(currVal < 0 || (currVal != 0 && index >= size) || (currVal != 0 && ck >= k))
            return;
        
        if(currVal == 0 && ck == k)
        {
            if(sNums.find(arr) == sNums.end())
            {
                out.push_back(arr);
                sNums.insert(arr);
            }
            return;
        }
        
        for(int i = index; i < size; i++)
        {
            arr.push_back(candidates[i]);
            currVal -= candidates[i];
            ck += 1;
            getCombinations(arr, i+1, currVal, size, k, ck);
            currVal += candidates[i];
            ck -= 1;
            arr.pop_back();
        };
        
        return;
    };
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        sNums.clear();
        out.clear();
        
        if(n == 0)
            return {{}};
        
        int size = 9, ck = 0;
        
        vector<int> arr;
        getCombinations(arr, 0, n, size, k, ck);
        
        return out;
    };
};