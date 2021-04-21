class Solution {
public:
    int minAddToMakeValid(string S) {
        
        int len = S.length(), count = 0;
        stack<char> s;
        
        for(int i = 0; i < len; i++)
        {
            if(S[i] == '(')
                s.push(S[i]);
            else{
                if(s.empty())
                    count++;
                else{
                    if(s.top() == '(')
                        s.pop();
                    else
                        count++;
                }
            }
        }
        
        return (count + s.size());
    }
};