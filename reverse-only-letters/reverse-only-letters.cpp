class Solution {
public:
    string reverseOnlyLetters(string S) {
        int len = S.length();
        int start = 0, end = len - 1;
        
        while(start < end)
        {
            while(start < len && isalpha(S[start]) == false)
                start++;
            
            while(end >= 0 && isalpha(S[end]) == false)
                end--;
            
            if(start >= end)
                break;
            
            swap(S[start], S[end]);
            start++;
            end--;
        };
        
        return S;
    }
};