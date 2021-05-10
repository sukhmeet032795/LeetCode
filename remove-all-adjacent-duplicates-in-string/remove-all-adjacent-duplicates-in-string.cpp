class Solution {
public:
    
    struct node{
        char _ch;
        int _count;
        node(char ch, int count) : _ch(ch), _count(count) {};
    };
    
    string removeDuplicates(string S) {
        
        int len = S.length(), end = 0;
        if(len == 0)
            return "";
        
        stack<node> s;
        while(end < len)
        {
            if(s.empty())
            {
                s.push(node(S[end], 1));
                end++;
            }
            else
            {
                if(!s.empty() && s.top()._ch == S[end])
                {
                    s.top()._count = s.top()._count + 1;
                    end++;
                    continue;
                }
                else if(!s.empty() && s.top()._ch != S[end])
                {
                    if(s.top()._count % 2 == 0){
                        s.pop();
                        continue;
                    }
                    else if(s.top()._count % 2 != 0)
                    {
                        s.top()._count = (s.top()._count % 2);
                    }
                }
                
                s.push(node(S[end], 1));
                end++;
            }
        }
        
        while(!s.empty())
        {
            if(s.top()._count % 2 == 0){
                s.pop();
                continue;
            }
            else if(s.top()._count % 2 != 0)
            {
                s.top()._count = (s.top()._count % 2);
                break;
            }
        }
        
        string out = "";
        while(!s.empty())
        {
            out = s.top()._ch + out;
            s.pop();
        }
        return out;
    };
};