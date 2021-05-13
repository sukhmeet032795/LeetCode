class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int len = prices.size(), Max = 0;
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
                
                if(prices[i] - s.top() > 0)
                {
                    Max += (prices[i] - s.top());
                    s.pop();
                    s.push(prices[i]);
                }
            }
        }
        
        return Max;
    }
};