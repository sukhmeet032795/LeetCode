class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len == 0 || len == 1) return (len == 0 ? 0 : cost[0]);
        
        vector<int> dp(len, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int idx = 2; idx < len; ++idx) {
            dp[idx] = cost[idx] + min(dp[idx - 1], dp[idx - 2]);
        }
        return min(dp[len - 1], dp[len - 2]);
    }
};