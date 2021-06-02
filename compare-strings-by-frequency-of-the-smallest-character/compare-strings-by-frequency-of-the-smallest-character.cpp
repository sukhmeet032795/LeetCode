class Solution {
public:
    
    int f(string &word)
    {
        int len = word.length();
        map<char, int> m;
        
        for(int i = 0; i < len; i++)
            m[word[i]]++;
        
        char ch = word[0];
        
        for(auto itr : m)
        {
            ch = min(ch, itr.first);
        };
        
        return m[ch];
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        map<int, int> m;
        
        for(int i = 0; i < words.size(); i++)
        {
            m[f(words[i])]++;
        };
        
        vector<int> out;
        for(int i = 0; i < queries.size(); i++)
        {
            int count = 0;
            int c1 = f(queries[i]);
            for(auto itr : m)
            {
                if(itr.first > c1)
                    count += itr.second;
            };
            out.push_back(count);
        }
        
        return out;
    };
};