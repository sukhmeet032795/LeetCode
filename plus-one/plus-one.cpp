class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1, indexOfNine;
        
        digits.insert(digits.begin(), 0);
        
        for (int i = (digits.size() - 1); i >= 0; i--) {
            int num = digits[i] + carry;
            carry = num / 10;
            digits[i] = (num % 10);
        }
        
        while(digits.size() != 1 && digits[0] == 0) {
            digits.erase(digits.begin());
        }
        
        return digits;
    }
};