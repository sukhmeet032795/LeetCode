class Solution {
public:
    
    struct node{
        char alph;
        int count;
        node(char al, int co) : alph(al), count(co) {};
    };
    
    string removeDuplicates(string S) {
        
        stack<node> s;
        int len = S.length(), count = 0;
        char alph;
        for(int i = 0; i < len;)
        {
            if(!s.empty())
            {
                node tmp = s.top();
                if(tmp.alph == S[i])
                {
                    tmp.count += 1;
                    s.pop();
                    // s.push(tmp);
                    i++;
                }
                else
                {
                    if(tmp.count > 1)
                    {
                        s.pop();
                    }
                    else
                    {
                        s.push(node(S[i], 1));
                        i++;
                    }
                }
            }
            else
            {
                s.push(node(S[i], 1));
                i++;
            }
        }
        
        while(!s.empty())
        {
            node tmp = s.top();
            if(tmp.count == 2)
                s.pop();
            else
                break;
        }
        
        string out = "";
        while(!s.empty())
        {
            node alp = s.top();
            s.pop();
            out = alp.alph + out;
        }
        
        return out;
    }
};