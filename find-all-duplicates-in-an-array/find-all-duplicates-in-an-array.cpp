class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> out;
        unordered_set<int> s;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]) != s.end())
            {
                out.push_back(nums[i]);
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        
        return out;
    }
};