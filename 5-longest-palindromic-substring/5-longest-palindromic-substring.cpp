class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length(), ind = 0, start = 0, end = 0, Max = 1, begin = 0;
        
        while(ind < len) {
            start = ind, end = (ind + 1);
            while(start >= 0 && end < len) {
                if (s[start] != s[end]) break;
                if ((end - start + 1) > Max) {
                    Max = (end - start + 1);
                    begin = start;
                }
                start--;
                end++;
            };
            
            start = ind - 1, end = ind + 1;
            while(start >= 0 && end < len) {
                if (s[start] != s[end]) break;
                if ((end - start + 1) > Max) {
                    Max = (end - start + 1);
                    begin = start;
                }
                start--;
                end++;
            };
            ind++;
        };
        
        return s.substr(begin, Max);
    }
};