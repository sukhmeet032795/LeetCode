class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int maxVal = 0;
        map<int, int> numsMap;
        for (auto num : nums) {
            ++numsMap[num];
            maxVal = max(maxVal, num);
        }
        
        vector<int> dp(maxVal + 1, 0);
        dp[1] = numsMap[1];
        for (int idx = 2; idx <= maxVal; ++idx) {
            dp[idx] = max(dp[idx - 1], dp[idx -  2] + (idx * numsMap[idx]));
        }
        
        return dp[maxVal];
    }
};