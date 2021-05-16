class Solution {
public:
    string smallestSubsequence(string S) {
        
        int len = S.length(), count = 0;
        stack<char> s;
        
        vector<bool> visited(26, false);
        vector<int> indexes(26, -1);
        
        for(int i = (len - 1); i >= 0 && count < 26; i--)
        {
            if(indexes[S[i]-'a'] == -1)
            {
                indexes[S[i]-'a'] = i;
                count++;
            }
        };
        
        for(int i = 0; i < len; i++)
        {
            int num = S[i] - 'a';
            if(visited[num] == true)
                continue;
            
            while(!s.empty() && s.top() > static_cast<char>(num+'a') && i < indexes[s.top()-'a'])
            {
                visited[s.top() - 'a'] = false;
                s.pop();
            }
            s.push(static_cast<char>(num+'a'));
            visited[num] = true;
        };
        
        string out = "";
        while(!s.empty())
        {
            out += s.top();
            s.pop();
        }    
        
        reverse(out.begin(), out.end());
        return out;
    }
};