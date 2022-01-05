class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPalin(string s)
    {
        for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    };
    
    void calc(vector<string> out, int index, string s)
    {
        if(s.length() == index)
            ans.push_back(out);
        
        string tmp = "";
        for(int i = index; i < s.length(); i++) {
            tmp.push_back(s[i]);
            if(isPalin(tmp)) {
                out.push_back(tmp);
                calc(out, i+1, s);
                out.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s)
    {
        ans.clear();
        if(s.length() == 0)
            return ans;
        
        vector<string> out;
        calc(out, 0, s);
        return ans;
    }
};