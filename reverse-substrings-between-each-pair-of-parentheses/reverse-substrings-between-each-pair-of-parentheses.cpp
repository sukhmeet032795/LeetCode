class Solution {
public:
    
    string reverseS(string s, int &ind)
    {
        int len = s.length();
        queue<char> s1;
        for( ; ind < len; ind++)
        {
            if(isalpha(s[ind]))
            {
                s1.push(s[ind]);
            }
            else if(s[ind] == '(')
            {
                int index = ind + 1;
                string tmp = reverseS(s, index);
                reverse(tmp.begin(), tmp.end());
                ind = index;
                for(auto itr : tmp)
                {
                    s1.push(itr);
                };
            }
            else if(s[ind] == ')')
            {
                break;
            }
        }
        
        string ans = "";
        while(!s1.empty())
        {
            ans = ans + s1.front();
            s1.pop();
        }
        return ans;
    }
    
    string reverseParentheses(string s) {
        
        int ind = 0;
        return reverseS(s, ind);
    }
};