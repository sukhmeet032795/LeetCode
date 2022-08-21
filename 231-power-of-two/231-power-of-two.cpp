class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n < 0)
            return false;
        
        int bit = 0;
        for(int i = 0; i < 32; i++) {
            int tmp = (n >> i) & 1;
            if (tmp)
                bit++;
        };
        
        return (bit == 1);
    }
};