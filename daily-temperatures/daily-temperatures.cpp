class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int len = T.size();
        vector<int> out(len, 0);
        stack<int> s;
        
        for(int i = 0; i < len; i++)
        {
            while(!s.empty() && T[s.top()] < T[i])
            {
                out[s.top()] = (i - s.top());
                s.pop();
            }
            s.push(i);
        }
        
        return out;
    }
};