class Solution {
public:
    int myAtoi(string str) {
        
        long int ans = 0;
        int number = 0, sign = 0;
        bool neg = false, numSet = false;
        
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
            {
                if(numSet){
                    if(neg == false)
                        return static_cast<int>(ans);
                    else
                    {
                        ans = 0 - ans;
                        return static_cast<int>(ans);
                    }
                }
                
                if(sign > 0)
                    return 0;
                
                continue;
            };
            
            if(str[i] == '+' || str[i] == '-')
            {
                if(numSet){
                    if(neg == false)
                        return static_cast<int>(ans);
                    else
                    {
                        ans = 0 - ans;
                        return static_cast<int>(ans);
                    }
                }
                
                if(sign >= 1)
                    return 0;
                sign++;
                neg = (str[i] == '+' ? false : true);
                continue;
            };
            
            if(str[i] < '0' || str[i] > '9')
            {
                if(numSet){
                    if(neg == false)
                        return static_cast<int>(ans);
                    else
                    {
                        ans = 0 - ans;
                        return static_cast<int>(ans);
                    }
                }
                return 0;
            };
            
            int num = str[i] - '0';
            ans = ans*10 + num;
            numSet = true;
            
            if((ans) > (INT_MAX))
            {
                if(neg == false)
                    return INT_MAX;
                else
                    return INT_MIN;
            };
        };
        
        if(neg)
        {
            ans = 0 - ans;
        };
        return static_cast<int>(ans);;
    }
};