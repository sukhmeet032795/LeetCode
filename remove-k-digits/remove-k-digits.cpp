class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int len = num.length();
        
        if(len == k)
            return "0";
        
        stack<int> s;
        for(int i = 0; i < len; i++)
        {
            while(!s.empty() && k != 0 && (num[s.top()] - '0') > (num[i] - '0'))
            {
                s.pop();
                k--;
            }
            s.push(i);
        }
        
        while(!s.empty() && k != 0)
        {
            s.pop();
            k--;
        }
        
        string ans = "";
        while(!s.empty())
        {
            int tmp = s.top();
            s.pop();
            ans = num[tmp] + ans;
        };
        
        while(ans.length() != 1 && ans[0] == '0')
        {
            ans.erase(ans.begin());
        }
        
        return ans;
    }
};