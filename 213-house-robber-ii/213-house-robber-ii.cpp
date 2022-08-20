class Solution {
public:
    int robMaxAmount(vector<int>& nums) {
        
        int len = nums.size();
        if (len == 1) return nums[0];
        
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for(int i = 2; i < len; i++) 
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return dp[len - 1];
    };
    
    int rob(vector<int>& nums) {
        
        int len = nums.size();
        if (len == 1) return nums[0];
        
        int last = nums[len - 1];
        nums.pop_back();
        int ans1 = robMaxAmount(nums);
        nums.push_back(last);
        
        int first = nums[0];
        nums.erase(nums.begin());
        int ans2 = robMaxAmount(nums);

        return max(ans1, ans2);
    };
};