class Solution {
public:
    int myAtoi(string s) {
        
        long int num = 0;
        bool neg = false, space = false, isNumSet = false, pos = false;
        
        for(int i = 0; i < s.length(); i++) {
            
            if (s[i] == ' ') {  
                if (neg || pos)
                    break;
                if (!isNumSet)
                    continue;
                break;
            } else if (s[i] == '-') {
                if (neg || pos || isNumSet)
                    break;
                neg = true;
                continue;
            } else if (s[i] == '+') {
                if (neg || pos || isNumSet)
                    break;
                pos = true;
                continue;
            } else if (!isdigit(s[i])) {
                break;
            } else {
                int tmp = s[i] - '0';
                num = num*10 + tmp;
                isNumSet = true;
                
                if((num) > (INT_MAX))
                {
                    if(neg == false)
                        return INT_MAX;
                    else
                        return INT_MIN;
                };
            }
        };
        num = ((neg) ? (-num) : (num));
        return static_cast<int>(num);
    }
};