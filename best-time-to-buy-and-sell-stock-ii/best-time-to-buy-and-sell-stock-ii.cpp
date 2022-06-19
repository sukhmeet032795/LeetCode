class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int len = prices.size(), ans = 0;
        stack<int> s;
        for (auto price: prices) {
            if (s.empty()) s.push(price);
            else {
                if (s.top() > price) {
                    s.pop();
                    s.push(price);
                } else {
                    ans += price - s.top();
                    s.pop();
                    s.push(price);
                }
            }
        }
        return ans;
    }
};