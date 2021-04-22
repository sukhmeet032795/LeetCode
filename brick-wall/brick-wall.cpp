class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int len = wall.size(), ans = INT_MAX;
        bool check = false;
        
        vector<int> indexes(len, 0), dp(len, 0);
        
        int Min = INT_MAX;
        for(int i = 0; i < len; i++)
        {
            dp[i] = wall[i][indexes[i]];
            Min = min(Min, dp[i]);
            indexes[i]++;
        }
        
        while(check != true)
        {
            int count = 0, nMin = INT_MAX;
            
            for(int i = 0; i < len; i++)
            {
                dp[i] -= Min;
                if(dp[i] == 0)
                {
                    if(indexes[i] == wall[i].size())
                    {
                        check = true;
                        break;
                    }
                    
                    count++;
                    dp[i] += wall[i][indexes[i]];
                    indexes[i]++;
                }
                nMin = min(nMin, dp[i]);
            }
            
            Min = nMin;
            ans = min(ans, (len - count));
        };
        
        return ans;
    }
};
