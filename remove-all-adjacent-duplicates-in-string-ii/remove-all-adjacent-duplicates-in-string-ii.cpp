class Solution {
public:
    
    struct node{
        char alph;
        int count;
        node(char al, int co) : alph(al), count(co) {};
    };
    
    string removeDuplicates(string S, int k) {
        
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
                    if(tmp.count != k)
                        s.push(tmp);
                    i++;
                }
                else
                {
                    if(tmp.count == k)
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
            if(tmp.count == k)
                s.pop();
            else
                break;
        }
        
        string out = "";
        while(!s.empty())
        {
            node alp = s.top();
            s.pop();
            while(alp.count--)
                out = alp.alph + out;
        }
        
        return out;
    }
};