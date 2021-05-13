class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int len = prices.size(), Max = INT_MIN;
        stack<int> s;
        
        for(int i = 0; i < len; i++)
        {
            if(s.empty())
            {
                s.push(prices[i]);
            }
            else 
            {
                if(s.top() > prices[i])
                {
                    s.pop();
                    s.push(prices[i]);
                }
                
                Max = max(Max, prices[i] - s.top());
            }
        }
        
        return (Max == INT_MIN ? 0 : Max);
    }
};