class Solution {
public:
    
    unordered_set<int> uSet;
    void validParen(string S)
    {
        int count = 0;
        stack<int> s;
        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] == '(')
            {
                s.push(i);
            }
            else
            {
                if(!s.empty() && S[s.top()] == '(' && S[i] == ')')
                {
                    s.pop();
                }
                else if(S[i] == ')')
                {
                    uSet.insert(i);
                }
            }
        }
        
        while(!s.empty())
        {
            uSet.insert(s.top());
            s.pop();
        }
    };
    
    string minRemoveToMakeValid(string s) {
        
        uSet.clear();
        validParen(s);
        
        string out = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]))
                out += s[i];
            else{
                if(uSet.find(i) == uSet.end())
                {
                    out += s[i];
                }
            }
        }
        
        return out;
    }
};