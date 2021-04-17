class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int len = arr.size();
        stack<int> s;
        vector<int> out(len, -1);
        
        for(int i = (len - 2); i >= 0; i--)
        {
            out[i] = max(arr[i+1], out[i+1]);
        }
        
        return out;
    }
};