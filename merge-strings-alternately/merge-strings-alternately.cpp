class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int len1 = word1.length(), len2 = word2.length(), curr1 = 0, curr2 = 0;
        
        string out = "";
        while(curr1 < len1 || curr2 < len2)
        {
            if(curr1 != len1)
                out += word1[curr1++];
            
            if(curr2 != len2)
                out += word2[curr2++];
        };
        
        return out;
    }
};