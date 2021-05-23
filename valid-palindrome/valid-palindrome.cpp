class Solution {
public:
    bool isPalindrome(string &str)
    {
        int start = 0, len = str.length(), end = len - 1;
        while(start < end)
        {
            while(start < end && (isalnum(str[start]) == false))
                start++;
            
            while(end > start && (isalnum(str[end]) == false))
                end--;
            
            if(tolower(str[start]) != tolower(str[end]))
                return false;
            start++;
            end--;
        };
        return true;
    };
};