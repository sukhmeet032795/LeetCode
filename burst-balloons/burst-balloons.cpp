class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        int len = nums.size();
        vector< vector<int> > dp(len+1, vector<int>(len+1, 0));
        
        for (int l = 2; l <= nums.size(); l++) {
            for (int i = 1; i <= (len - l); i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MIN;
                for (int k = i; k < j && j < len; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + nums[i-1]*nums[j]*nums[k]);
                }
            }
        }
        return dp[1][len-1];
    }
};