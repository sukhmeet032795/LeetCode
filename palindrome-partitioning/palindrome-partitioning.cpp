class Solution {
public:
    
    vector< vector<string> > arr;
    
    bool checkPalin(string ans)
    {
       int j = 0, k = ans.length()-1;
        while(j < k)
        {
            if(ans[j] != ans[k])
                return false;
            j++;
            k--;
        }
        return true;
    };
    
    void solution(string s, vector<string> ans, int start)
    {
        if(start == s.length())
        {
            arr.push_back(ans);
            return;
        }
        
        string s1 = "";
        for(int i = start; i < s.length(); i++)
        {
            s1 = s1 + s[i];
            if(checkPalin(s1) == false)
                continue;
            ans.push_back(s1);
            solution(s, ans, i+1);
            ans.pop_back();
        }
    };
    
    vector<vector<string>> partition(string s) {
        
        arr.clear();
        vector<string> ans;
        if(s == ""){
            arr.push_back(ans);
            return arr;
        }
        
        solution(s, ans, 0);
        
        return arr;
    }
};