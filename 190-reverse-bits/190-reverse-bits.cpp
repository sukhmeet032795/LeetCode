class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t out = 0;
        for(int i = 0; i < 32; i++) {
            
            int num = n >> i & 1;
            out = out | (num << (31 - i));
        }
        return out;
    }
};