class Solution {
public:
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        map<char, char> m;
        map<char, char> m1;
        vector<string> out;
        for(int i = 0; i < words.size(); i++)
        {
            bool check = true;
            for(int j = 0; j < pattern.length(); j++)
            {
                if(m.find(pattern[j]) == m.end() && m1.find(words[i][j]) == m1.end())
                {
                    m[pattern[j]] = words[i][j];
                    m1[words[i][j]] = pattern[j];
                }
                else if(m[pattern[j]] != words[i][j] || m1[words[i][j]] != pattern[j])
                {
                    check = false;
                    break;
                }
            }
            m.clear();
            m1.clear();
            if(check)
                out.push_back(words[i]);
        }
        
        return out;
    }
};