class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.length() == 0)
            return 0;
        
        size_t ind = haystack.find(needle);
        if(ind == string::npos)
            return -1;
        return ind;
    }
};