class Solution {
public:
    void reverseWords(vector<char>& s) {
        
        reverse(s.begin(), s.end());
        int start = 0, end = 0, len = s.size();
        
        while(end < len)
        {
            if(s[end] == ' ' || end == (len - 1))
            {
                // cout<<start<<" "<<end<<endl;
                int tmp = (end == (len - 1)) ? end : end - 1;
                while(start < tmp)
                {
                    swap(s[start], s[tmp]);
                    start++;
                    tmp--;
                }
                start = end + 1;
            }
            end++;
        }
    }
};