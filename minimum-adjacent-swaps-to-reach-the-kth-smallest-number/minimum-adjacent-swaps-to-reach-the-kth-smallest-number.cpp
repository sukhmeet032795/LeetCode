class Solution {
public:
    int getMinSwaps(string num, int k) {
        
        string num1=num;
        while(k--)
        {
            next_permutation(num.begin(),num.end());
        }
        int n=num.length();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(num[i]!=num1[i])
            {
                int j=i+1;
                for(;j<n;j++)
                {
                    if(num1[j]==num[i])
                    {
                        ans+=j-i;
                        break ;
                    }
                }
                while(j!=i)
                {
                    swap(num1[j],num1[j-1]);
                    j--;
                }
            }
        }
        
        return ans;
    }
};