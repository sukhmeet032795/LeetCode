class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int Max = INT_MIN;
        stack<int> s;
        for(auto price : prices) {
            if(s.empty()) {
                s.push(price);
            }
            else if (s.top() > price) {
                s.pop();
                s.push(price);
            }
            else {
                int diff = abs(price - s.top());
                Max = max(diff, Max);
            }
        }
        
        return (Max == INT_MIN ? 0 : Max);
    }
};