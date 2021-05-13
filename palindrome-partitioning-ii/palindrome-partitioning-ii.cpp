class Solution {
public:
    int minCut(string s) {
        
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        
        for(int i = 0; i < len; i++)
            dp[i][i] = true;
        
        for(int i = 0; i < (len-1); i++)
            if(s[i] == s[i+1])
                dp[i][i+1] = true;
        
        for(int l = 2; l <= len; l++)
        {
            for(int i = 0; i <= (len - l); i++)
            {
                int j = (i + l -1);
                if(s[i] == s[j] && dp[i+1][j-1] == true)
                    dp[i][j] = true;
            }
        }
        
        // for(int i = 0; i < len; i++)
        // {
        //     for(int j = 0; j < len; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> dp1(len, 0);
        
        for(int i = 0; i < len; i++)
        {
            if(dp[0][i] != true)
            {
                int Min = INT_MAX;
                for(int j = 0; j < i; j++)
                {
                    if(dp[j+1][i] == true)
                        Min = min(Min, dp1[j] + 1);
                }
                dp1[i] = Min;
            }
        }
        
        return dp1[len-1];
    }
};