class Solution {
public:
    
    int rob1(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> dp(len, 0);
        
        if(len == 1)
            return nums[0];
        
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for(int i = 2; i < len; i++)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        
        return dp[len-1];
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> nums1(nums.begin(), nums.end()-1);
        int ans1 = rob1(nums1);
        
        vector<int> nums2(nums.begin() + 1, nums.end());
        int ans2 = rob1(nums2);
        
        return max(ans1, ans2);
    }
};