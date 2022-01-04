class Solution {
public:
    int bitwiseComplement(int n) {
        
        if (n == 0)
            return 1;
        
        int ans = 0, count = 0;
        while(n) {
            int val = n & 1;
            if (val == 0) {
                ans = ans | (1 << count);
            }
            count += 1;
            n = n >> 1;
        }
        return ans;
    }
};