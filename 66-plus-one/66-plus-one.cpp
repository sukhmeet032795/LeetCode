class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int len = digits.size(), carry = 1;
        for(int i = (len - 1); i >= 0; i--) {
            int tmp = digits[i] + carry;
            carry = tmp / 10;
            digits[i] = tmp % 10;
        };
        
        if (carry) {
            digits.insert(digits.begin(), 1, 1);
        };
        
        while(digits.size() != 1 && digits[0] == 0) {
            digits.erase(digits.begin());
        };
        
        return digits;
    }
};