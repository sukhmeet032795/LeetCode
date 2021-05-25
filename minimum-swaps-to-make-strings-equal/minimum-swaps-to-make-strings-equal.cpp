class Solution {
public:
    int minimumSwap(string s1, string s2) {
        
        int x=0,y=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(s1[i]=='x')
                    x++;
                else
                    y++;
            }
        }
        int res=x/2+y/2;
        x=x%2,y=y%2;
        if(x!=y)
            return -1;
        if(x==1)
            res+=2;
        return res;
    }
};