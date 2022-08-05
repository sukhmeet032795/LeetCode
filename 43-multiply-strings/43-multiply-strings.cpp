class Solution {
public:
    
    string addStrings(const string &num1, const string &num2) {
        
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
        
        while(out.length() != 1 && out[0] == '0') {
            out.erase(out.begin());
        }
        
        return out;
    };
    
    string multiply(string num1, string num2) {
        
        if (num1.length() > num2.length())
            return multiply(num2, num1);
        
        int len1 = num1.length(), len2 = num2.length(), carry = 0;
        string out = "", zeros = "0";
        
        for(int i = (len2 - 1); i >= 0; i--) {
            
            string out1 = "";
            carry = 0;
            for(int j = (len1 - 1); j >= 0; j--) {
                int tmp = ((num2[i] - '0') * (num1[j] - '0')) + carry;
                carry = (tmp / 10);
                out1 = to_string(tmp % 10) + out1;
            };
            
            if (carry) {
                out1 = to_string(carry) + out1;
            };
            
            if (!out.length()) { out = out1; }
            else {
                out1 = out1 + zeros;
                zeros += "0";
                out = addStrings(out, out1);
            };
        };
        
        return out;
    }
};