class Solution {
public:
    int minInsertions(string S) {
        
        int len = S.length(), count = 0;
        stack<char> s;
        
        for(int i = 0; i < len; i++)
        {
            if(S[i] == '(')
                s.push(S[i]);
            else
            {
                if(s.empty()){
                    if((i+1) < len)
                    {
                        if(S[i+1] != ')')
                            count += 2;
                        else
                        {
                            count += 1;
                            i++;
                        }
                    }
                    else
                        count += 2;
                }
                else if(s.top() == '(')
                {
                    s.pop();
                    if((i+1) < len)
                    {
                        if(S[i+1] != ')')
                            count += 1;
                        else
                            i++;
                    }
                    else
                        count += 1;
                }
            }
        }
        
        return (count + (s.size()*2));
    }
};