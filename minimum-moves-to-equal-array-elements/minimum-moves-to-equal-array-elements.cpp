class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int count = 0, diff = 0, len = nums.size();
        
        for(int i = 1; i < len; i++)
        {
            count += (nums[i] - nums[0]);
        };
        
        return count;
    }
};


