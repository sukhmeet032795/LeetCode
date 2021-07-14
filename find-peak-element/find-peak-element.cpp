class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int size = nums.size(), Max = INT_MIN, ind = 0;
        for(int i = 0; i < size; i++)
        {
            if(Max < nums[i])
            {
                Max = nums[i];
                ind = i;
            }
        }
        
        return ind;
    }
};