class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int len1 = num1.length(), len2 = num2.length(), ind1 = (len1 - 1), ind2 = (len2 - 1), carry = 0;
        
        string out = "";
        while(ind1 >= 0 && ind2 >= 0) {
            int tmp = (num1[ind1--] - '0') + (num2[ind2--] - '0') + carry;
            carry = tmp / 10;
            out = to_string(tmp % 10) + out;
        };
        
        while(ind1 >= 0) {
            int tmp = (num1[ind1--] - '0') + carry;
            carry = tmp / 10;
            out = to_string(tmp % 10) + out;
        };
        
        while(ind2 >= 0) {
            int tmp = (num2[ind2--] - '0') + carry;
            carry = tmp / 10;
            out = to_string(tmp % 10) + out;
        };
        
        if (carry) {
            out = to_string(1) + out;
        };
        
        return out;
    };
};