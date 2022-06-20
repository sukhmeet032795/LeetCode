class Solution {
public:
    int reverse(int x) {
        
        int x1 = 0;
        
        while(x) {
            int tmp = x % 10;
            x /= 10;
            if (x1 > (INT_MAX/10) || x1 < (INT_MIN/10))
                return 0;
            x1 = x1*10 + tmp;
        }
        
        return x1;
    }
};