class Solution {
public:
    
    int validate(const int& start, const int&end, const vector<int>& v, const int &k) {
        int Max = 0;
        for (auto v1 : v) {
            Max = max(Max, v1);    
        };
        return ((end - start - Max) <= k);
    };
    
    int characterReplacement(string s, int k) {
        
        int start = 0, end = 0, len = s.length(), Max = 0;
        vector<int> arr(26, 0);
        while(end < len) {
            arr[s[end] - 'A']++;
            end++;
            
            while (!validate(start, end, arr, k)) {
                arr[s[start] - 'A']--;
                start++;
            };
            Max = max(Max, (end - start));
        };
        return Max;
    };
};