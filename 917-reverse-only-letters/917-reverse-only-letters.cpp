class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        for(int i = 0, j = (s.length() - 1); i < j; i++, j--) {
            while(!isalpha(s[i]) && (i < j)) i++;
            while(!isalpha(s[j]) && (i < j)) j--;
            if (i >= j)
                break;
            swap(s[i], s[j]);
        }
        return s;
    }
};