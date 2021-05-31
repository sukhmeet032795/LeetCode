class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        unordered_map<char, char> m = { {'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'} };
        string num1 = "";
        for(int i = 0; i < num.length(); i++)
        {
            char tmp = num[i];
            if(m.find(tmp) == m.end())
                return false;
            num1 = num1 + m[tmp];
        };
        reverse(num1.begin(), num1.end());
        if(num1 != num)
            return false;
        return true;
    }
};