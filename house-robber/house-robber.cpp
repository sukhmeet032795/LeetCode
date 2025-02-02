class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1) return (len == 0 ? 0 : nums[0]);
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int idx = 2; idx < len; ++idx) {
            dp[idx] = max(dp[idx - 1], dp[idx - 2] + nums[idx]);
        }
        return dp[len - 1];
    }
};